/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/12 13:47:22 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/25 21:39:40 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"
#include <stdio.h>

void	print_stack(t_stack *stack);

static void	lowhigh(int *lo, int *hi, t_stack *stack, size_t n)
{
	size_t	i;

	i = 0;
	*lo = stack_at(stack, 0);
	*hi = stack_at(stack, 0);
	while (i < n)
	{
		if (stack_at(stack, i) < *lo)
			*lo = stack_at(stack, i);
		if (stack_at(stack, i) > *hi)
			*hi = stack_at(stack, i);
		i++;
	}
}

typedef enum e_qsort_flag
{
	QSORT_FROMA = 1 << 0,
	QSORT_ASC = 1 << 1,
}	t_qsort_flag;

static size_t	partition(t_context *ctx, int pivot, size_t n, t_qsort_flag flags)
{
	size_t	i;
	size_t	moved;

	i = 0;
	moved = 0;
	while (i++ < n)
	{
		if ((flags & QSORT_ASC && stack_at(ctx->a, 0) <= pivot)|| stack_at(ctx->a, 0) > pivot)
		{
			if (flags & QSORT_FROMA)
				pushb(ctx->a, ctx->b);
			else
				pusha(ctx->a, ctx->b);
			moved++;
		}
		else
		{
			if (flags & QSORT_FROMA)
				rotatea(ctx->a);
			else
				rotateb(ctx->a);
		}
	}
	return (moved);
}

static void	quick_sort(t_context *ctx, size_t n, t_qsort_flag flags)
{
	int		low;
	int		high;
	int		pivot;
	size_t	moved;
	size_t	kept;
	size_t	i;

	if (n < 2)
		return ;
	lowhigh(&low, &high, ctx->a, n);
	if (low == high)
		return ;
	pivot = (low + high) / 2;
	moved = partition(ctx, pivot, n, flags);
	i = 0;
	kept = n - moved;
	while (i++ < kept)
		reverse_rotatea(ctx->a);
	quick_sort(ctx, kept, flags);
	quick_sort(ctx, moved, flags ^ (QSORT_ASC | QSORT_FROMA));
	while (moved--)
		pusha(ctx->a, ctx->b);
}

void	sort_complex(t_context *ctx)
{
	quick_sort(ctx, ctx->a->len, QSORT_ASC | QSORT_FROMA);
}
