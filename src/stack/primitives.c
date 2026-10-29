/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   primitives.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 14:28:06 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/29 15:14:54 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"
#include <stdlib.h>

t_stack	stack_new(size_t init)
{
	t_stack	stack;

	stack = (t_stack){.data = NULL, .len = 0, .cap = init};
	stack.data = malloc(sizeof(int) * init);
	return (stack);
}

void	stack_swap(t_stack *stack)
{
	int	temp;

	temp = stack->data[stack->len];
	stack->data[stack->len] = stack->data[stack->len - 1];
	stack->data[stack->len - 1] = temp;
}

void	pusha(t_stack *a, t_stack *b)
{
	ft_printf("pa\n");
	if (!b->len)
		return ;
	a->data[a->len++] = b->data[b->len--];
}
