/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adaptive.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/26 13:54:35 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/27 17:03:58 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	sort_linear(t_context *ctx)
{
	(void)ctx;
}

void	sort_adaptive(t_context *ctx)
{
	if (ctx->bench->disorder < 0.2)
		sort_linear(ctx);
	else if (ctx->bench->disorder >= 0.2 && ctx->bench->disorder < 0.5)
		sort_medium(ctx);
	else
		sort_complex(ctx);
}
