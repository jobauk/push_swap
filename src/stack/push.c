/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:20:56 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/10/30 14:33:06 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"
#include <stdlib.h>

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

