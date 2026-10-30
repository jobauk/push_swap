/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:25:43 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/10/30 15:50:04 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "stack.h"

static void	stack_reverse_rotate(t_stack *stack)
{
	int	tmp;

	if (!stack->len)
		return ;
	tmp = stack->data[stack->len];
	ft_memmove(stack->data + stack->len,
		stack->data + stack->len - 1, stack->len - 1);
	stack->data[0] = tmp;
}

void	rotatea(t_stack *a)
{
	ft_printf("rra\n");
	stack_reverse_rotate(a);
}

void	rotateb(t_stack *b)
{
	ft_printf("rrb\n");
	stack_reverse_rotate(b);
}

void	rotate_all(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	stack_reverse_rotate(a);
	stack_reverse_rotate(b);
}
