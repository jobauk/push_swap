/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/06 13:56:28 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/16 18:20:35 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include <stddef.h>
# include "stack.h"

void sort_simple(t_stack *a);

void sort_medium(t_stack *a, t_stack *b);

void sort_complex(t_stack *a, t_stack *b);

#endif
