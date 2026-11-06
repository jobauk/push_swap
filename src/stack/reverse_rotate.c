/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:25:43 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/06 13:58:03 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"

static void	stack_reverse_rotate(t_stack *stack)
{
	if (stack->start == 0)
		stack->start = stack->len;
	else
		stack->start--;
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
