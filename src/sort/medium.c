/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/17 14:12:48 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/24 15:20:57 by kivan-ei      ########   odam.nl         */
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
	while (i < chunk_size && i < b->len)
	{
		if (stack_at(b, i) > stack_at(b, max))
			max = i;
		i++;
	}
	return (max);
}

static int	push_chunk(t_stack *a, t_stack *b, size_t low, size_t size)
{
	size_t	remaining;
	size_t	rank;
	int		op_count;

	remaining = size;
	op_count = 0;
	while (a->len && remaining)
	{
		rank = find_rank(a, b, stack_at(a, 0));
		if (rank >= low && rank < low + size)
		{
			op_count += pushb(a, b);
			remaining--;
		}
		else
			op_count += rotatea(a);
	}
	return (op_count);
}

static int	pull_max(t_stack *a, t_stack *b, size_t size)
{
	size_t	i;
	size_t	j;
	int		op_count;
	
	i = chunk_max(b, size);
	j = i;
	op_count = 0;
	while (i--)
		op_count += rotateb(b);
	pusha(a, b);
	while (j--)
		op_count += reverse_rotateb(b);
	return (op_count);
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
