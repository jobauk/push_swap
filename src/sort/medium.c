/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/17 14:12:48 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/26 13:43:19 by kivan-ei      ########   odam.nl         */
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

static size_t	chunk_max(t_context *ctx, size_t chunk_size)
{
	size_t	i;
	size_t	max;

	i = 0;
	max = 0;
	while (i < chunk_size && i < ctx->b->len)
	{
		if (stack_at(ctx->b, i) > stack_at(ctx->b, max))
			max = i;
		i++;
	}
	return (max);
}

static void	push_chunk(t_context *ctx, size_t low, size_t size)
{
	size_t	remaining;
	size_t	rank;

	remaining = size;
	while (ctx->a->len && remaining)
	{
		rank = find_rank(ctx->a, ctx->b, stack_at(ctx->a, 0));
		if (rank >= low && rank < low + size)
		{
			ctx->bench->pb_ops += pushb(ctx->a, ctx->b);
			remaining--;
		}
		else
			ctx->bench->ra_ops += rotatea(ctx->a);
	}
}

static void	pull_max(t_context *ctx)
{
	size_t	i;
	
	i = chunk_max(ctx, ctx->b->len);
	if (i <= ctx->b->len / 2)
		while (i--)
			ctx->bench->rb_ops += rotateb(ctx->b);
	else
	{
		i = ctx->b->len - i;
		while (i--)
			ctx->bench->rrb_ops += reverse_rotateb(ctx->b);
	}
	ctx->bench->pa_ops += pusha(ctx->a, ctx->b);
}

void	sort_medium(t_context *ctx)
{
	size_t	chunk_size;
	size_t	low;

	chunk_size = 1;
	while (chunk_size <= ctx->a->len / chunk_size)
		chunk_size++;
	chunk_size--;
	low = 0;
	while (ctx->a->len)
	{
		push_chunk(ctx, low, chunk_size);
		low += chunk_size;
	}
	while (ctx->b->len)
		pull_max(ctx);
}
