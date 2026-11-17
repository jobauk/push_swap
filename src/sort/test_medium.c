/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_medium.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/17 14:12:48 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/17 23:31:58 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <stdio.h>

static size_t	find_rank(t_stack *a, t_stack *b, int value)
{
	size_t	i;
	size_t	rank;

	i = 0;
	rank = 0;
	while (i < a->len)
		if (stack_at(a, i++) < value)
			rank++;
	i = 0;
	while (i < b->len)
		if (stack_at(b, i++) < value)
			rank++;
	return (rank);
}

static size_t	chunk_max(t_stack *b, size_t chunk_size)
{
	size_t	i;
	size_t	max;
	
	i = 0;
	max = 0;
	while (i < chunk_size)
	{
		if (stack_at(b, i) > stack_at(b, max))
			max = i;
		i++;
	}
	return(max);
}

static void	push_chunk(t_stack *a, t_stack *b, size_t low, size_t size)
{
	size_t	remaining;
	size_t	rank;

	remaining = size;
	while (remaining)
	{
		rank = find_rank(a, b, stack_at(a, 0));
		if (rank >= low && rank < low + size)
		{
			pushb(a, b);
			remaining--;
		}
		else
			rotatea(a);
	}
}

static void	pull_max(t_stack *a, t_stack *b, size_t size)
{
	size_t	i;
	size_t	j;

	i = chunk_max(b, size);
	j = i;
	while (i--)
		rotateb(b);
	pusha(a, b);
	while (j--)
		reverse_rotateb(b);
}

void	sort_medium(t_bench *bench, t_stack *a, t_stack *b)
{
	size_t	chunk_size;
	size_t	low;

	(void)bench;
	chunk_size = 1;
	while (chunk_size <= a->len / chunk_size)
		chunk_size++;
	chunk_size--;
	low = 0;
	while (a->len)
	{
		push_chunk(a, b, low, chunk_size);
		low += chunk_size;
	}
	while (b->len)
		pull_max(a, b, chunk_size);
}

// void	sort_medium(t_stack *a, t_stack *b)
// {
// 	int		chunks;
// 	int		range;
// 	int		min;
// 	int		num;
// 	size_t 	i;
// 	size_t	j;
// 	int		temp;
	
// 	chunks = ft_sqrt(a->len);
// 	min = ft_range(a, chunks, &range);
// 	num = 0;
// 	temp = range;
// 	while (a->len != 0)
// 	{
// 		fill_b(a, b, min, min + range);
// 		min += (range + 1);
// 	}
// 	while (num < chunks)
// 	{
// 		while (range + 1 > 0 && b->len)
// 		{
// 			i = find_max(b, range + 1);
// 			j = i;
// 			while (i-- > 1)
// 				rotateb(b);
// 			pusha(a, b);
// 			while (j-- > 1)
// 				reverse_rotateb(b);
// 			range--;
// 		}
// 		range = temp;
// 		num++;
// 	}
// }
