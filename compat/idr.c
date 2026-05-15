
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/err.h>
#include <linux/string.h>
#include <linux/idr.h>
#include <linux/spinlock.h>
#include <linux/export.h>


#ifndef HAVE_IDR_GET_NEXT_EXPORTED
void *idr_get_next(struct idr *idp, int *nextidp)
{
	struct idr_layer *p, *pa[MAX_LEVEL];
	struct idr_layer **paa = &pa[0];
	int id = *nextidp;
	int n, max;

	/* find first ent */
	n = idp->layers * IDR_BITS;
	max = 1 << n;
	p = rcu_dereference(idp->top);
	if (!p)
		return NULL;

	while (id < max) {
		while (n > 0 && p) {
			n -= IDR_BITS;
			*paa++ = p;
			p = rcu_dereference(p->ary[(id >> n) & IDR_MASK]);
		}

		if (p) {
			*nextidp = id;
			return p;
		}

		id += 1 << n;
		while (n < fls(id)) {
			n += IDR_BITS;
			p = *--paa;
		}
	}
	return NULL;
}
EXPORT_SYMBOL(idr_get_next);
#endif

#ifndef HAVE_IDA_SIMPLE_GET
static DEFINE_SPINLOCK(simple_ida_lock);

void ida_simple_remove(struct ida *ida, unsigned int id)
{
	ida_free(ida, id);
}

EXPORT_SYMBOL(ida_simple_remove);

int ida_simple_get(struct ida *ida, unsigned int start,
		   unsigned int end, gfp_t gfp_mask)
{
	unsigned int max = end ? end - 1 : 0x7fffffffU;

	return ida_alloc_range(ida, start, max, gfp_mask);
}

EXPORT_SYMBOL(ida_simple_get);
#endif /* HAVE_IDA_SIMPLE_GET */

#ifndef HAVE_IDR_GET_NEXT_UL_EXPORTED

#ifdef HAVE_IDR_RT
void *idr_get_next_ul(struct idr *idr, unsigned long *nextid)
{
	struct radix_tree_iter iter;
	void __rcu **slot;
	unsigned long base = idr->idr_base;
	unsigned long id = *nextid;

	id = (id < base) ? 0 : id - base;
	slot = radix_tree_iter_find(&idr->idr_rt, &iter, id);
	if (!slot)
		return NULL;

	*nextid = iter.index + base;
	return rcu_dereference_raw(*slot);
}
EXPORT_SYMBOL(idr_get_next_ul);
int idr_alloc_u32(struct idr *idr, void *ptr, u32 *nextid,
		unsigned long max, gfp_t gfp)
{
	struct radix_tree_iter iter;
	void __rcu **slot;
	unsigned int base = idr->idr_base;
	unsigned int id = *nextid;

	if (WARN_ON_ONCE(!(idr->idr_rt.xa_flags & ROOT_IS_IDR)))
		idr->idr_rt.xa_flags |= IDR_RT_MARKER;

	id = (id < base) ? 0 : id - base;
	radix_tree_iter_init(&iter, id);
	slot = idr_get_free(&idr->idr_rt, &iter, gfp, max - base);
	if (IS_ERR(slot))
		return PTR_ERR(slot);

	*nextid = iter.index + base;
	/*there is a memory barrier inside radix_tree_iter_replace() */
	radix_tree_iter_replace(&idr->idr_rt, &iter, slot, ptr);
	radix_tree_iter_tag_clear(&idr->idr_rt, &iter, IDR_FREE);

	return 0;
}
EXPORT_SYMBOL_GPL(idr_alloc_u32);
#endif /* HAVE_IDR_RT */

#endif /* HAVE_IDR_GET_NEXT_UL_EXPORTED */
