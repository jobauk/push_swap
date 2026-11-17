/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:25:49 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/17 14:14:54 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"

void	stack_rotate(t_stack *stack)
{
	if (stack->len < 2)
		return ;
	*stack_at_mut(stack, stack->len) = stack_at(stack, 0);
	stack->start = (stack->start + 1) % stack->cap;
}

int	rotatea(t_stack *a)
{
	ft_printf("ra\n");
	stack_rotate(a);
	return (1);
}

int	rotateb(t_stack *b)
{
	ft_printf("rb\n");
	stack_rotate(b);
	return (1);
}

int	rotate_all(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	stack_rotate(a);
	stack_rotate(b);
	return (1);
}
