/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_double.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/19 15:49:01 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/25 13:31:30 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	check_double(t_stack *a)
{
	size_t i;
	size_t j;

	j = 0;
	while (j <= a->len)
	{
		i = j + 1;
		while (i <= a->len)
		{
			if (a->data[j] == a->data[i])
				return (-1);	
			i++;
		}
		j++;
	}
	return (1);
}
