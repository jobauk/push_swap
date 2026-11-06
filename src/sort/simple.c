/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/06 13:54:35 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/06 17:25:30 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void sort_simple(t_stack *a)
{
	size_t i;

	i = 0;
	while (i < a->len)
	{
		if (stack_at(a, a->len - 1) < stack_at(a, a->len - 2))
			reverse_rotatea(a);
		else
		{
			swapa(a);
			reverse_rotatea(a);
		}
		i++;
	}
}
