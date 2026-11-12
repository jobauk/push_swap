/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:20:56 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/12 14:51:44 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"

void	stack_rotate(t_stack *stack);

void	stack_reverse_rotate(t_stack *stack);

static void	stack_push(t_stack *a, t_stack *b)
{
	// if (a->len)
	// {
	// 	*stack_at_mut(a, a->len - 1) = stack_at(b, 0);
	// 	stack_rotate(a);
	// 	stack_reverse_rotate(b);
	// }
	// else
	// stack_rotate(a);
	stack_rotate(a);
	*stack_at_mut(a, 0) = stack_at(b, 0);
	stack_reverse_rotate(b);
	a->len++;
	b->len--;
}

void	pusha(t_stack *a, t_stack *b)
{
	ft_printf("pa\n");
	stack_push(a, b);
}

void	pushb(t_stack *a, t_stack *b)
{
	ft_printf("pb\n");
	stack_push(b, a);
}
