#include "dllist.h"

void	dllist_add(t_dllist *l, size_t pos, void *elem)
{
	t_dlnode	*insertion_node;
	t_dlnode	*node;

	if (l == NULL || pos > l->length || elem == NULL)
		exit(1);
	node = malloc(sizeof(t_dlnode));
	if (!node)
		exit(1);
	node->data = malloc(l->elem_size);
	if (!(node->data))
		exit(1);
	insertion_node = get_node(l, pos);
	node->prev = insertion_node->prev;
	node->next = insertion_node;
	node->next->prev = node;
	node->prev->next = node;
	++l->length;
	ft_memcpy(node->data, elem, l->elem_size);
}

void	dllist_get(t_dllist *l, size_t pos, void *elem_out)
{
	t_dlnode	*node;

	if (l == NULL || pos >= l->length || elem_out == NULL)
		exit(1);
	node = get_node(l, pos);
	ft_memcpy(elem_out, node->data, l->elem_size);
}

void	dllist_iterator(t_dllist *l, t_iterator *it, size_t start, size_t end)
{
	t_dllist_it	*istruct;

	if (l == NULL || it == NULL || start >= l->length || end >= l->length)
		exit(1);
	it->dispose = it_dispose;
	it->next = it_next;
	it->elem = it_elem;
	istruct = malloc(sizeof(t_dllist_it));
	if (!istruct)
		exit(1);
	istruct->started = 0;
	istruct->rem = end - start;
	if (start > end)
		istruct->rem = start - end;
	istruct->fwd = start <= end;
	istruct->node = get_node(l, start);
	it->istruct = istruct;
}

void	dllist_remove(t_dllist *l, size_t pos, void *elem_out)
{
	t_dlnode	*node;

	if (l == NULL || pos >= l->length)
		exit(1);
	node = get_node(l, pos);
	node->prev->next = node->next;
	node->next->prev = node->prev;
	if (elem_out != NULL)
		ft_memcpy(elem_out, node->data, l->elem_size);
	--l->length;
	free(node->data);
	free(node);
}

void	dllist_set(t_dllist *l, size_t pos, void *elem, void *old_elem)
{
	t_dlnode	*node;

	if (l == NULL || pos >= l->length || elem == NULL)
		exit(1);
	node = get_node(l, pos);
	if (old_elem != NULL)
		ft_memcpy(old_elem, node->data, l->elem_size);
	ft_memcpy(node->data, elem, l->elem_size);
}
