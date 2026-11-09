/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/06 13:54:35 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/09 16:52:55 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	print_stack(t_stack *stack);

void	sort_simple(t_stack *a)
{
	size_t i;
	size_t j;

	i = 0;
	if (!a->len)
		return ;
	while (i++ < a->len - 1)
	{
		j = 0;
		
		while (j++ < a->len - 1)
		{
			if (stack_at(a, 0) > stack_at(a, 1))
			{
				swapa(a);
				// print_stack(a);
			}
			reverse_rotatea(a);
			// print_stack(a);
		}
		reverse_rotatea(a);
		// print_stack(a);
	}
}
