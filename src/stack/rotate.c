/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:25:49 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/10/30 15:44:06 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "stack.h"

static void	stack_rotate(t_stack *stack)
{
	int	tmp;

	if (!stack->len)
		return ;
	tmp = stack->data[0];
	ft_memmove(stack->data, stack->data + 1, stack->len - 1);
	stack->data[stack->len] = tmp;
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
