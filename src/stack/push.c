/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:20:56 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/10/29 15:24:10 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"
#include <stdlib.h>

void	pusha(t_stack *a, t_stack *b)
{
	ft_printf("pa\n");
	if (!b->len)
		return ;
	if (a->len < a->cap)
	a->data[a->len++] = b->data[b->len--];
}

void	pushb(t_stack *a, t_stack *b)
{
	ft_printf("pb\n");
	if (!a->len)
		return ;
	if (b->len < b->cap)
	b->data[b->len++] = a->data[a->len--];
}

