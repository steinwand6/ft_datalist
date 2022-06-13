#ifndef CHAINEDHASHTABLE_H
# define CHAINEDHASHTABLE_H

# include <limits.h>
# include "dllist.h"

#define RAND_VAL 1824387193
#define RAND_Z1 2773421004
#define RAND_Z2 3470426971

typedef unsigned int	uint32;

typedef struct s_chainedhashtable {
	t_dllist	*array;
	size_t		length;
	size_t		elem_size;
	size_t		w;
	size_t		d;
	int			z;
	int			(*hashcode)(void*);
}	t_c_hashtable;

int			c_hashtable_add(t_c_hashtable *table, void *elem);
void		c_hashtable_clear(t_c_hashtable *table);
void		c_hashtable_dispose(t_c_hashtable *table);
void		c_hashtable_find(t_c_hashtable *table);
void		c_hashtable_init(t_c_hashtable *table, size_t elem_size,
				int (*hashcode)(void*), int (*random)(void));
void		c_hashtable_remove(t_c_hashtable *table, void *elem);
size_t		hash(t_c_hashtable *table, int elem_hashcode);
t_dllist	*allocate_table(t_c_hashtable *table);
void		resize(t_c_hashtable *table);
void		chainedhashtable_init(t_c_hashtable *table, size_t elem_size,
								  int (*hashcode)(void*), int (*random)(void));
int			chainedhashtable_add(t_c_hashtable *table, void *elem);
void		chainedhashtable_clear(t_c_hashtable *table);
void		chainedhashtable_dispose(t_c_hashtable *table);
int			chainedhashtable_find(t_c_hashtable *table, void *elem);
void		chainedhashtable_remove(t_c_hashtable *table, void *elem);
int			hash_code(void *ptr);
#endif
