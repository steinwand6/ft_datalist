#ifndef ITERATOR_H
#define ITERATOR_H

typedef struct s_iterator {
	int		(*next)(struct t_iterator* iter);
	void*	(*elem)(struct t_iterator* iter);
	void	(*dispose)(struct t_iterator* iter);
	void*	istrunct;
}	t_iterator;

#endif
