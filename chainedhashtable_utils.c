#include "chainedhashtable.h"

size_t	hash(t_c_hashtable *table, int elem_hashcode)
{
	return ((unsigned int)(table->z * elem_hashcode) >> (table->w - table->d));
}

int	hash_code(void *ptr)
{
	long	p;
	long	s;
	long	zi;
	int		i;
	char	*str;

	str = (char*)ptr;
	p = (1L << 32) - 5;
	s = 0;
	zi = 1;
	i = 0;
	while (i < ft_strlen(str))
	{
		s = (s + zi * (((int)(str[i]) * RAND_Z2) >> 1)) % p;
		zi = (zi * RAND_Z1) % p;
		i++;
	}
	s = (s + zi * (p - 1)) % p;
	return (int)s;
}

t_dllist	*allocate_table(t_c_hashtable *table)
{
	t_dllist	*dllist_array;
	size_t		i;
	size_t		size;

	size = 1 << table->d;
	dllist_array = malloc(sizeof(t_dllist) * size);
	if (dllist_array == NULL)
		exit(1);
	i = 0;
	while (i < size)
	{
		dllist_init(dllist_array + i, table->elem_size);
		i++;
	}
	return (dllist_array);
}

void	resize(t_c_hashtable *table)
{
	t_dllist	*list;
	t_dllist	*old_array;
	size_t		old_array_size;
	t_iterator	it;
	size_t		i;

	old_array = table->array;
	old_array_size = 1 << table->d;
	table->d = 1;
	while ((1 << table->d) <= table->length)
		++table->d;
	table->array = allocate_table(table);
	i = 0;
	while (i < old_array_size)
	{
		list = old_array + i;
		if (list->length > 0) {
			dllist_iterator(list, &it, 0, list->length - 1);
			while (it.next(&it))
				chainedhashtable_add(table, it.elem(&it));
			it.dispose(&it);
		}
		dllist_dispose(list);
	}
	free(old_array);
}

void	chainedhashtable_init(t_c_hashtable *table, size_t elem_size,
							  int (*hashcode)(void*), int (*random)(void))
{
	if (table == NULL || hashcode == NULL || elem_size <= 0)
		exit(1);
	table->elem_size = elem_size;
	table->w = sizeof(int) * CHAR_BIT;
	table->d = 1;
	table->hashcode = hashcode;
	table->length = 0;
	table->z = RAND_VAL;
	table->array = allocate_table(table);
}
