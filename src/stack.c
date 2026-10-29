/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 17:30:55 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/29 15:13:23 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stddef.h>

int stack_push_a(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_b->len == 0)
		return (0);
	if (stack_a->len + 1 <= stack_a->cap)
		stack_b->data[stack_b->len] =  stack_a->data[stack_a->len + 1];
}
