/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:25:49 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/25 13:33:50 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"

int	stack_rotate(t_stack *stack)
{
	if (stack->len < 2)
		return (0);
	*stack_at_mut(stack, stack->len) = stack_at(stack, 0);
	stack->start = (stack->start + 1) % stack->cap;
	return (1);
}

int	rotatea(t_stack *a)
{
	ft_printf("ra\n");
	return (stack_rotate(a));
}

int	rotateb(t_stack *b)
{
	ft_printf("rb\n");
	return (stack_rotate(b));
}

int	rotate_all(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	return (stack_rotate(a) || stack_rotate(b));
}
