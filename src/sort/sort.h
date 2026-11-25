/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/06 13:56:28 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/25 14:03:05 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"
# include "stack.h"
# include <stddef.h>

void	sort_simple(t_context *ctx);

void	sort_medium(t_context *ctx);

void	sort_complex(t_bench *bench, t_stack *a, t_stack *b);

#endif
