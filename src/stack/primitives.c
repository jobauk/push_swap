/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   primitives.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 14:28:06 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/29 16:00:12 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"
#include <stdlib.h>
#include "libft.h"

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

void	stack_rotate(t_stack *stack)
{
	int	tmp;

	if (!stack->len)
		return ;
	tmp = stack->data[0];
	ft_memmove(stack->data, stack->data + 1, stack->len - 1);
	stack->data[stack->len] = tmp;
}

void	stack_reverse_rotate(t_stack *stack)
{
	int	tmp;

	if (!stack->len)
		return ;
	tmp = stack->data[stack->len];
	ft_memmove(stack->data + stack->len, stack->data + stack->len - 1, stack->len - 1);
	stack->data[0] = tmp;
}
