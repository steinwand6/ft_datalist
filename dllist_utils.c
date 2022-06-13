#include "dllist.h"

int	it_next(t_iterator *it)
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

void	*it_elem(t_iterator *it)
{
	t_dllist_it	*a;

	a = it->istruct;
	return (a->node->data);
}

void	it_dispose(t_iterator *it)
{
	free(it->istruct);
}

t_dlnode	*get_node(t_dllist *l, size_t pos)
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
