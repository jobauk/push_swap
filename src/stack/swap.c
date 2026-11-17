/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:24:12 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/17 14:15:10 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"

static void	stack_swap(t_stack *stack)
{
	int	temp;

	if (stack->len < 2)
		return ;
	temp = stack_at(stack, 0);
	*stack_at_mut(stack, 0) = stack_at(stack, 1);
	*stack_at_mut(stack, 1) = temp;
}

int	swapa(t_stack *a)
{
	ft_printf("sa\n");
	stack_swap(a);
	return (1);
}

int	swapb(t_stack *b)
{
	ft_printf("sb\n");
	stack_swap(b);
	return (1);
}

int	swap_all(t_stack *a, t_stack *b)
{
	ft_printf("ss\n");
	stack_swap(a);
	stack_swap(b);
	return (1);
}
