/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:25:43 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/09 17:00:36 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"

static void	stack_reverse_rotate(t_stack *stack)
{
	if (stack->start == stack->len)
		stack->start = 1;
	else
		stack->start++;
}

void	reverse_rotatea(t_stack *a)
{
	ft_printf("ra\n");
	stack_reverse_rotate(a);
}

void	reverse_rotateb(t_stack *b)
{
	ft_printf("rb\n");
	stack_reverse_rotate(b);
}

void	reverse_rotate_all(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	stack_reverse_rotate(a);
	stack_reverse_rotate(b);
}
