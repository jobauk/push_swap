/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 17:44:30 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/17 14:13:39 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>

typedef struct s_stack
{
	int			*data;
	size_t		start;
	size_t		len;
	size_t		cap;
}	t_stack;

// primitives
t_stack	stack_new(size_t init);
void	stack_free(t_stack *stack);
void	stack_append(t_stack *stack, int n);
int		stack_at(t_stack *stack, size_t idx);
int		*stack_at_mut(t_stack *stack, size_t idx);

// rotate
int		rotatea(t_stack *a);
int		rotateb(t_stack *b);
int		rotate_all(t_stack *a, t_stack *b);

// reverse rotate
int		reverse_rotatea(t_stack *a);
int		reverse_rotateb(t_stack *b);
int		reverse_rotate_all(t_stack *a, t_stack *b);

// push
int		pusha(t_stack *a, t_stack *b);
int		pushb(t_stack *a, t_stack *b);

// swap
int		swapa(t_stack *a);
int		swapb(t_stack *b);
int		swap_all(t_stack *a, t_stack *b);

#endif
