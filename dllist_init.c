#include "dllist.h"

void	dllist_dispose(t_dllist *l)
{
	t_dlnode	*node;
	t_dlnode	*old_node;

	if (l == NULL)
		exit(1);
	node = l->dummy->next;
	while (node != l->dummy)
	{
		free(node->data);
		old_node = node;
		node = node->next;
		free(old_node);
	}
	free(l->dummy);
}

void	dllist_init(t_dllist *l, size_t elem_size)
{
	if (l == NULL || elem_size <= 0)
		exit(1);
	l->dummy = malloc(sizeof(t_dlnode));
	if (l->dummy == NULL)
		exit(1);
	l->length = 0;
	l->elem_size = elem_size;
	l->dummy->next = l->dummy;
	l->dummy->prev = l->dummy;
	l->dummy->data = NULL;
}
