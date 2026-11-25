/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/12 13:47:22 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/24 22:21:08 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

void	print_stack(t_stack *stack);

void	sort_complex(t_bench *bench, t_stack *a, t_stack *b)
{
	(void)bench;
	(void)b;
	print_stack(a);
}
