/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/06 13:56:28 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/17 22:47:15 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"
# include "stack.h"
# include <stddef.h>

void	sort_simple(t_bench *bench, t_stack *a);

void	sort_medium(t_bench *bench, t_stack *a, t_stack *b);

void	sort_complex(t_bench *bench, t_stack *a, t_stack *b);

#endif
