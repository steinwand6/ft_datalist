#ifndef ITERATOR_H
# define ITERATOR_H

typedef struct s_iterator {
	int		(*next)(struct s_iterator*);
	void	*(*elem)(struct s_iterator*);
	void	(*dispose)(struct s_iterator*);
	void	*istruct;
}	t_iterator;

#endif
