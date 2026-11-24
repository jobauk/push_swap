/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:20:56 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/24 14:55:27 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"

static int	stack_push(t_stack *a, t_stack *b)
{
	if (b->len == 0)
		return (0);
	a->start = (a->start + a->cap - 1) % a->cap;
	*stack_at_mut(a, 0) = stack_at(b, 0);
	b->start = (b->start + 1) % b->cap;
	b->len--;
	a->len++;
	return (1);
}

int	pusha(t_stack *a, t_stack *b)
{
	ft_printf("pa\n");
	return (stack_push(a, b));
}

int	pushb(t_stack *a, t_stack *b)
{
	ft_printf("pb\n");
	return (stack_push(b, a));
}
