#include "chainedhashtable.h"

int		chainedhashtable_add(t_c_hashtable *table, void *elem)
{
	t_dllist	*list;

	if (table == NULL || elem == NULL)
		exit(1);
	if (chainedhashtable_find(table, elem))
		return (0);
	if (table->length + 1 > (1 << table->d))
		resize(table);
	list = table->array + hash(table, table->hashcode(elem));
	dllist_add(list, list->length, elem);
	++table->length;
	return (1);
}

void	chainedhashtable_clear(t_c_hashtable *table)
{
	if (table == NULL)
		exit(1);
	table->d = 1;
	table->length = 0;
	table->array = allocate_table(table);
}

void	chainedhashtable_dispose(t_c_hashtable *table)
{
	size_t	i;
	size_t	array_size;

	if (table == NULL)
		exit(1);
	array_size = 1 < table->d;
	i = 0;
	while (i < array_size)
	{
		dllist_dispose(table->array + 1);
		i++;
	}
	free(table->array);
}

int	chainedhashtable_find(t_c_hashtable *table, void *elem)
{
	t_dllist	*list;
	t_iterator	it;

	if (table == NULL || elem == NULL)
		exit(1);
	list = table->array + hash(table, table->hashcode(elem));
	if (list->length > 0)
	{
		dllist_iterator(list, &it, 0, list->length - 1);
		while (it.next(&it))
		{
			if (ft_memcmp(elem, it.elem(&it), table->elem_size) == 0)
			{
				it.dispose(&it);
				return (1);
			}
		}
		it.dispose(&it);
	}
	return (0);
}

void	chainedhashtable_remove(t_c_hashtable *table, void *elem)
{
	t_dllist	*list;
	t_iterator	it;
	size_t		i;

	if (table == NULL || elem == NULL)
		exit(1);
	list = table->array + hash(table, table->hashcode(elem));
	if (list->length > 0)
	{
		i = 0;
		dllist_iterator(list, &it, 0, list->length - 1);
		while (it.next(&it)) {
			if (ft_memcmp(it.elem(&it), elem, table->elem_size))
			{
				it.dispose(&it);
				dllist_remove(list, i, NULL);
				--table->length;
				return ;
			}
			i++;
		}
	}
}
