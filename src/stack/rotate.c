/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/29 15:25:49 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/06 13:51:29 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"

static void	stack_rotate(t_stack *stack)
{
	stack->start = stack->start % stack->len;
}

void	rotatea(t_stack *a)
{
	ft_printf("ra\n");
	stack_rotate(a);
}

void	rotateb(t_stack *b)
{
	ft_printf("rb\n");
	stack_rotate(b);
}

void	rotate_all(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	stack_rotate(a);
	stack_rotate(b);
}
