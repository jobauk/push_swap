/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/06 13:56:28 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/17 17:43:55 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"
# include "stack.h"
# include <stddef.h>

void sort_simple(t_bench *bench, t_stack *a);

void	sort_medium(t_stack *a, t_stack *b);
int	ft_range(t_stack *a, int chunks, int *range);
void fill_b(t_stack *a, t_stack *b, int min, int max);
int	ft_sqrt(size_t nmbr);

void sort_complex(t_bench *bench, t_stack *a, t_stack *b);

#endif
