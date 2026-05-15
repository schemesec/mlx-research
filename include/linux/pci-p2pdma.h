#ifndef _COMPAT_LINUX_PCI_P2PDMA_H
#define _COMPAT_LINUX_PCI_P2PDMA_H 1

#include_next <linux/pci-p2pdma.h>
#include <linux/dma-mapping.h>
#include <linux/scatterlist.h>

/*
 * OFED_CX3_COMPAT_PCI_P2PDMA_MAP_SG
 *
 * MLNX_OFED 4.9 expects pci_p2pdma_map_sg(), but newer kernels expose
 * pci_p2pdma_state() / pci_p2pdma_map_type() instead.
 *
 * This compatibility helper preserves the old behavior as much as possible:
 *   - normal non-P2P pages return 0 so the caller can use the normal DMA path
 *   - unsupported P2P mappings return 0
 *   - P2P bus-address mappings fill sg_dma_address/sg_dma_len and return nents
 *   - through-host-bridge mappings fall back to dma_map_sg()
 */
static inline int pci_p2pdma_map_sg(struct device *dev,
                                    struct scatterlist *sg,
                                    int nents,
                                    enum dma_data_direction dir)
{
        struct pci_p2pdma_map_state state = {};
        struct scatterlist *s;
        int i;

        for_each_sg(sg, s, nents, i) {
                switch (pci_p2pdma_state(&state, dev, sg_page(s))) {
                case PCI_P2PDMA_MAP_NONE:
                        return 0;
                case PCI_P2PDMA_MAP_NOT_SUPPORTED:
                        return 0;
                case PCI_P2PDMA_MAP_BUS_ADDR:
                        sg_dma_address(s) =
                                pci_p2pdma_bus_addr_map(state.mem, sg_phys(s));
                        sg_dma_len(s) = s->length;
                        break;
                case PCI_P2PDMA_MAP_THRU_HOST_BRIDGE:
                        return dma_map_sg(dev, sg, nents, dir);
                case PCI_P2PDMA_MAP_UNKNOWN:
                default:
                        return 0;
                }
        }

        return nents;
}

#endif
