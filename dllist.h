#ifndef DLLIST_H
#define DLLIST_H

#include <stdlib.h>

#include "libft.h"
#include "iterator.h"

typedef struct	s_dlnode {
	void			*data;
	struct s_dlnode	*next;
	struct s_dlnode	*prev;
}	t_dlnode;

typedef struct {
	size_t		elem_size;
	size_t		length;
	t_dlnode	*dummy;
}	t_dllist;

/* FUNCTION
 *      dllist_add
 *
 * DESCRIPTION
 *      Adds an element to the specified position in the list.
 *
 * PARAMETERS
 *      l           A valid pointer to an initialized dllist_t struct.
 *      pos         The position where the element will be inserted.
 *      elem        The element that will be copied into the list.
 */
void	dllist_add(t_dllist *l, size_t pos, void *elem);

/* FUNCTION
 *      dllist_dispose
 *
 * DESCRIPTION
 *      Releases all memory allocated by other dllist_* functions. If you have
 *      any pointer references to nodes, they will be invalid after a call to
 *      this function.
 *
 * PARAMETERS
 *      l           A valid pointer to an initialized dllist_t struct.
 */
void	dllist_dispose(t_dllist *l);

/* FUNCTION
 *      dllist_get
 *
 * DESCRIPTION
 *      Retrieves an element from the list.
 *
 * PARAMETERS
 *      l           A valid pointer to an initialized dllist_t struct.
 *      pos         The position of the element that will be retrieved.
 *      elem_out    The element at pos will be copied into the memory pointed to
 *                  by this argument.
 */
void	dllist_get(t_dllist *l, size_t pos, void *elem_out);

/* FUNCTION
 *      dllist_init
 *
 * DESCRIPTION
 *      Initializes an dllist_t struct.
 *
 * PARAMETERS
 *      l           A valid pointer to an dllist_t struct.
 *      elem_size   Size of the elements that will be stored in the list.
 */
void	dllist_init(t_dllist *l, size_t elem_size);

/* FUNCTION
 *      dllist_iterator
 *
 * ITERABLE
 *      FORWARD     start <= end
 *      REVERSE     start >  end
 *
 * DESCRIPTION
 *      Initializes an iterator_t for the specified range [start, end].
 *
 * PARAMETERS
 *      l           A valid pointer to an initialized dllist_t struct.
 *      it          A valid pointer to an iterator_t struct.
 *      start       Start position (inclusive, must be less than length).
 *      end         End position (inclusive, must be less than length).
 */
void	dllist_iterator(t_dllist *l, t_iterator *it, size_t start, size_t end);

/* FUNCTION
 *      dllist_remove
 *
 * DESCRIPTION
 *      Retrieves an element from the list.
 *
 * PARAMETERS
 *      l           A valid pointer to an initialized dllist_t struct.
 *      pos         The position of the element that will be removed.
 *      elem_out    If not null, the removed element will be copied into this
 *                  memory.
 */
void	dllist_remove(t_dllist *l, size_t pos, void *elem_out);

/* FUNCTION
 *      dllist_set
 *
 * DESCRIPTION
 *      Set an element at the specified position.
 *
 * PARAMETERS
 *      l           A valid pointer to an initialized dllist_t struct.
 *      pos         The position of the element that will be set.
 *      elem        The new element that will replace the element at pos.
 *      old_elem    If not null, the old element at this position will be copied
 *                  into this memory.
 */
void	dllist_set(t_dllist *l, size_t pos, void *elem, void *old_elem);
