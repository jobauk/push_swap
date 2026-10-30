/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   primitives.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 14:28:06 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/30 15:47:39 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stack	stack_new(size_t init)
{
	t_stack	stack;

	stack = (t_stack){.data = NULL, .len = 0, .cap = init};
	stack.data = malloc(sizeof(int) * init);
	return (stack);
}

void	stack_append(t_stack *stack, int n)
{
	stack->data[stack->len++] = n;
}
