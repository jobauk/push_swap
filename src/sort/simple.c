/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/06 13:54:35 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/06 14:35:55 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void sort_simple(t_stack *a)
{
	size_t i;

	i = 0;
	while (i < a->len)
	{
		if (stack_at(a, a->len - 1) > stack_at(a, a->len - 2))
			rotatea(a);
		else
		{
			swapa(a);
			rotatea(a);
		}
		i++;
	}
}
