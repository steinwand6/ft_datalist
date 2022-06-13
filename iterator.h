#ifndef ITERATOR_H
#define ITERATOR_H

typedef struct s_iterator {
	int		(*next)(struct s_iterator* iter);
	void*	(*elem)(struct s_iterator* iter);
	void	(*dispose)(struct s_iterator* iter);
	void*	istruct;
}	t_iterator;

#endif
