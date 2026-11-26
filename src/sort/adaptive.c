/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adaptive.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/26 13:54:35 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/26 15:45:30 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_adaptive(t_context *ctx)
{
	if (ctx->bench->disorder < 0.2)
		sort_simple();
	if (ctx->bench->disorder >= 0.2 && ctx->bench->disorder < 0.5)
		sort_medium(ctx);
	if (ctx->bench->disorder >= 0.5)
		sort_complex(ctx);
}