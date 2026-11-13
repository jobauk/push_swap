/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:25:43 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/13 16:20:22 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"

void	stack_reverse_rotate(t_stack *stack)
{
	int	last;

	if (stack->len < 2)
		return ;
	last = stack_at(stack, stack->len - 1);
	stack->start = (stack->start + stack->cap - 1) % stack->cap;
	*stack_at_mut(stack, 0) = last;
}

void	reverse_rotatea(t_stack *a)
{
	ft_printf("rra\n");
	stack_reverse_rotate(a);
}

void	reverse_rotateb(t_stack *b)
{
	ft_printf("rrb\n");
	stack_reverse_rotate(b);
}

void	reverse_rotate_all(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	stack_reverse_rotate(a);
	stack_reverse_rotate(b);
}
