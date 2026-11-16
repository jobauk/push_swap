/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/12 13:47:22 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/16 17:13:22 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"

void	print_stack(t_stack *stack);

static size_t	partition(t_stack *stack)
{
	size_t	i;
	int		pivot;

	i = 0;
	pivot = stack_at(stack, stack->len - 1);
	while (i < stack->len)
	{
		if (stack_at(stack, 0) < pivot)
		{
			swapa(stack);
			rotatea(stack);
		}
		i++;
	}
	ft_printf("pivot: %d\n", pivot);
	return (stack->len - 1);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	(void)b;
	print_stack(a);
	partition(a);
}
