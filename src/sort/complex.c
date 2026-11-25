/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/12 13:47:22 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/25 15:30:53 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"
#include <stdio.h>

void	print_stack(t_stack *stack);

static int	midpoint(t_stack *stack)
{
	size_t	i;
	int		lo;
	int		hi;

	i = 0;
	lo = stack_at(stack, 0);
	hi = stack_at(stack, 0);
	while (i < stack->len)
	{
		if (stack_at(stack, i) < lo)
			lo = stack_at(stack, i);
		if (stack_at(stack, i) > hi)
			hi = stack_at(stack, i);
		i++;
	}
	return ((lo + hi) / 2);
}

static size_t	partition(t_stack *a, t_stack *b, size_t n, int asc)
{
	size_t	moved;
	
	int	pivot = midpoint(a);
	moved = 0;
	while (n--)
	{
		if (asc && stack_at(a, 0) <= pivot)
		{
			pushb(a, b);
			moved++;
		}
		else
			rotatea(a);
	}
	return (n - moved);
}

static void	quick_sort(t_stack *a, t_stack *b, size_t n, int asc)
{
	size_t	moved;
	size_t	kept;

	kept = partition(a, b, n, asc);
	moved = n + kept;
	while (kept--)
		reverse_rotatea(a);
	quick_sort(a, b, kept, 1);
	quick_sort(b, a, moved, 0);
	while (moved)
		pusha(a, b);
	// fprintf(stderr, "a:\n");
	// print_stack(a);
	// fprintf(stderr, "b:\n");
	// print_stack(b);
	// fprintf(stderr, "\n");
	// partition(a, b, a->len, 1);

	// fprintf(stderr, "a:\n");
	// print_stack(a);
	// fprintf(stderr, "b:\n");
	// print_stack(b);
	// fprintf(stderr, "\n");
	// partition(a, b, a->len, 1);

	// fprintf(stderr, "a:\n");
	// print_stack(a);
	// fprintf(stderr, "b:\n");
	// print_stack(b);
	// fprintf(stderr, "\n");
	// partition(a, b, a->len, 1);

	// fprintf(stderr, "a:\n");
	// print_stack(a);
	// fprintf(stderr, "b:\n");
	// print_stack(b);
	// fprintf(stderr, "\n");
	// partition(a, b, a->len, 1);

	// fprintf(stderr, "a:\n");
	// print_stack(a);
	// fprintf(stderr, "b:\n");
	// print_stack(b);
	// fprintf(stderr, "\n");
	// partition(a, b, a->len, 1);

	// fprintf(stderr, "a:\n");
	// print_stack(a);
	// fprintf(stderr, "b:\n");
	// print_stack(b);
	// fprintf(stderr, "\n");
	// partition(a, b, a->len, 1);

	// if (a->len > 1 && stack_at(a, 0) > stack_at(a, 1))
	// 	swapa(a);

	// while (b->len)
	// {
	// 	fprintf(stderr, "a:\n");
	// 	print_stack(a);
	// 	fprintf(stderr, "b:\n");
	// 	print_stack(b);
	// 	fprintf(stderr, "\n");
	// 	if (stack_at(b, 0) > stack_at(b, 1))
	// 		pusha(a, b);
	// 	else
	// 	{
	// 		swapb(b);
	// 		pusha(a, b);
	// 	}
	// }
}

void	sort_complex(t_bench *bench, t_stack *a, t_stack *b)
{
	(void)bench;
	(void)b;
	quick_sort(a, b, a->len, 1);
}
