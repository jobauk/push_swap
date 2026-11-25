/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/06 13:54:35 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/25 14:02:57 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"
#include "stack.h"

void	sort_simple(t_context *ctx)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!ctx->a->len)
		return ;
	while (i++ < ctx->a->len - 1)
	{
		j = 0;
		while (j++ < ctx->a->len - 1)
		{
			if (stack_at(ctx->a, 0) > stack_at(ctx->a, 1))
				ctx->bench->sa_ops += swapa(ctx->a);
			ctx->bench->ra_ops += rotatea(ctx->a);
		}
		ctx->bench->ra_ops += rotatea(ctx->a);
	}
}
