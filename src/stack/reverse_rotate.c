/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:25:43 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/10/30 14:21:47 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"
#include <stdlib.h>

void	rotatea(t_stack *a)
{
	ft_printf("rra\n");
	stack_reverse_rotate(a);
}

void	rotateb(t_stack *b)
{
	ft_printf("rrb\n");
	stack_reverse_rotate(b);
}