/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   primitives.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 14:28:06 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/13 16:19:47 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stack	stack_new(size_t init)
{
	t_stack	stack;

	stack = (t_stack){.data = NULL, .start = 0, .len = 0, .cap = init};
	stack.data = malloc(sizeof(int) * init);
	return (stack);
}

void	stack_free(t_stack *stack)
{
	free(stack->data);
}

int	*stack_at_mut(t_stack *stack, size_t idx)
{
	return (stack->data + (stack->start + idx) % stack->cap);
}

int	stack_at(t_stack *stack, size_t idx)
{
	return (*stack_at_mut(stack, idx));
}

void	stack_append(t_stack *stack, int n)
{
	*stack_at_mut(stack, stack->len) = n;
	stack->len++;
}
