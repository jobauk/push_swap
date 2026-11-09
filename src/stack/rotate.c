/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:25:49 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/09 15:36:09 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"

static void	stack_rotate(t_stack *stack)
{
	if (stack->cap)
		stack->start = (stack->start - 1 + stack->cap) % stack->cap;
	else
		stack->start = 0;
}

void	rotatea(t_stack *a)
{
	ft_printf("ra\n");
	stack_rotate(a);
}

void	rotateb(t_stack *b)
{
	ft_printf("rb\n");
	stack_rotate(b);
}

void	rotate_all(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	stack_rotate(a);
	stack_rotate(b);
}
