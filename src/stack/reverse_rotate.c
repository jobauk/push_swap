/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:25:43 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/24 14:54:45 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"

int	stack_reverse_rotate(t_stack *stack)
{
	int	last;

	if (stack->len < 2)
		return (0);
	last = stack_at(stack, stack->len - 1);
	stack->start = (stack->start + stack->cap - 1) % stack->cap;
	*stack_at_mut(stack, 0) = last;
	return (1);
}

int	reverse_rotatea(t_stack *a)
{
	ft_printf("rra\n");
	return (stack_reverse_rotate(a));
}

int	reverse_rotateb(t_stack *b)
{
	ft_printf("rrb\n");
	return (stack_reverse_rotate(b));
}

int	reverse_rotate_all(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	return (stack_reverse_rotate(a) || stack_reverse_rotate(b));
}
