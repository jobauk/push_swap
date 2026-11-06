/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 17:44:30 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/06 13:55:06 by jaukes        ########   odam.nl         */
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

// rotate
void	rotatea(t_stack *a);
void	rotateb(t_stack *b);
void	rotate_all(t_stack *a, t_stack *b);

// reverse rotate
void	reverse_rotatea(t_stack *a);
void	reverse_rotateb(t_stack *b);
void	reverse_rotate_all(t_stack *a, t_stack *b);

// push
void	pusha(t_stack *a, t_stack *b);
void	pushb(t_stack *a, t_stack *b);

// swap
void	swapa(t_stack *a);
void	swapb(t_stack *b);
void	swap_all(t_stack *a, t_stack *b);

#endif
