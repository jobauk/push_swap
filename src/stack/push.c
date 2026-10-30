/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:20:56 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/10/30 15:50:27 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"

static void	stack_push(t_stack *a, t_stack *b)
{
	if (!a->len)
		return ;
	if (b->len < b->cap)
		b->data[b->len++] = a->data[a->len--];
}

void	pusha(t_stack *a, t_stack *b)
{
	ft_printf("pa\n");
	stack_push(a, b);
}

void	pushb(t_stack *a, t_stack *b)
{
	ft_printf("pb\n");
	stack_push(b, a);
}
