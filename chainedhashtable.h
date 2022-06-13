#ifndef CHAINEDHASHTABLE_H
# define CHAINEDHASHTABLE_H

# include "dllist.h"

typedef struct s_chainedhashtable {
	t_dllist	*array;
	size_t		length;
	size_t		elem_size;
	size_t		w;
	size_t		d;
	int			z;
	int			(*hashcode)(void*);
}	t_c_hashtable;

int		c_hashtable_add(t_c_hashtable *table, void *elem);
void	c_hashtable_clear(t_c_hashtable *table);
void	c_hashtable_dispose(t_c_hashtable *table);
void	c_hashtable_find(t_c_hashtable *table);
void	c_hashtable_init(t_c_hashtable *table, size_t elem_size,
			 int (*hashcode)(void*), int (*random)(void));
void	c_hashtable_remove(t_c_hashtable *table, void *elem);
