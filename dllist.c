#include <stdlib.h>
#include <string.h>

#include "dllist.h"
#include "iterator.h"
#include "libft/iterator.h"

typedef struct	s_dllist_it {
	t_dlnode	*node;
	size_t		rem;
	int			fwd;
	int			started;
}	t_dllist_it;

static int	it_next(t_iterator *it)
{
	t_dllist_it	*a;

	a = it->istruct;
	if (!a->started)
		return (a->started = 1);
	if (a->rem == 0)
		return (0);
	if (a->fwd)
		a->node = a->node->next;
	else
		a->node = a->node->prev;
	a->rem--;
	return (1);
}

static void	*it_elem(t_iterator *it)
{
	t_dllist_it	*a;

	a = it->istruct;
	return a->node->data;
}

static void	it_dispose(t_iterator *it)
{
	free(it->istruct);
}

static t_dlnode	*get_node(t_dllist *l, size_t pos)
{
	t_dlnode	*node;
	size_t		i;

	if (pos < l->length / 2)
	{
		node = l->dummy->next;
		i = 0;
		while (i < pos)
		{
			node = node->next;
			i++;
		}
	}
	else
	{
		node = l->dummy;
		i = l->length;
		while (i > pos)
		{
			node = node->prev;
			i--;
		}
	}
	return (node);
}

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
	insertiton_node = get_node(l, pos);
	node->prev = insertion_node->prev;
	node->next = insertion_node;
	node->next->prev = node;
	node->prev->next = node;
	++l->length;
	ft_memcpy(node->data, elem, l->elem_size);
}

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

void	dllist_get(t_dllist *l, size_t pos, void *elem_out)
{
	t_dlnode	*node;

	if (l == NULL || pos >= l->length || elem_out == NULL)
		exit(1);
	node = get_node(l, pos);
	ft_memcpy(elem_out, node->data, l->elem_size);
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
	istruct->node ~ get_node(i, start);
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
	if (old_node != NULL)
		ft_memcpy(old_node, node->data, l->elem_size);
	ft_memcpy(node->data, elem, l->elem_size);
}
