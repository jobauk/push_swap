/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:24:12 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/10/30 15:47:41 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"

static void	stack_swap(t_stack *stack)
{
	int	temp;

	temp = stack->data[stack->len];
	stack->data[stack->len] = stack->data[stack->len - 1];
	stack->data[stack->len - 1] = temp;
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
