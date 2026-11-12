/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:24:12 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/11 12:19:27 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"

static void	stack_swap(t_stack *stack)
{
	int	temp;

	temp = stack_at(stack, 0);
	*stack_at_mut(stack, 0) = stack_at(stack, 1);
	*stack_at_mut(stack, 1) = temp;
}

void	swapa(t_stack *a)
{
	ft_printf("sa\n");
	stack_swap(a);
}

void	swapb(t_stack *b)
{
	ft_printf("sb\n");
	stack_swap(b);
}

void	swap_all(t_stack *a, t_stack *b)
{
	ft_printf("ss\n");
	stack_swap(a);
	stack_swap(b);
}
