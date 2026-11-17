/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_medium.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/17 14:12:48 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/17 17:37:43 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <stdio.h>
# include "push_swap.h"

size_t check_chunks(t_stack *b, int range)
{
	int i;
	size_t j;
	size_t k;
	
	k = 0;
	i = stack_at(b, 0);
	j = 0;
	while (j < (size_t)range)
	{
		if (stack_at(b, j) > i)
		{
			i = stack_at(b, j);
			k = j;
		}
		j++;
	}
	return(k);
}

void	sort_medium(t_stack *a, t_stack *b)
{
	int		chunks;
	int		range;
	int		min;
	int		num;
	size_t 	i;
	size_t	j;
	int		temp;
	
	chunks = ft_sqrt(a->len);
	min = ft_range(a, chunks, &range);
	num = 0;
	temp = range;
	while (a->len != 0)
	{
		fill_b(a, b, min, min + range);
		min += (range + 1);
	}
	while (num < chunks)
	{
		while (range + 1 > 0 && b->len)
		{
			i = check_chunks(b, range + 1);
			j = i;
			while (i-- > 1)
				rotateb(b);
			pusha(a, b);
			while (j-- > 1)
				reverse_rotateb(b);
			range--;
		}
		range = temp;
		num++;
	}
}
