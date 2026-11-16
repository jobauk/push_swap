/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/11 15:24:34 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/16 17:36:34 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <stdio.h>
# include "push_swap.h"

int ft_sqrt(size_t len)
{
    size_t nmbr = len;
    int sqrt = 0;
    size_t uneven = 1;

    while (nmbr >= uneven) {
        nmbr = nmbr - uneven;
        uneven = uneven + 2;
        sqrt = sqrt + 1;
    }
	printf("%d", sqrt);
	return (sqrt);
}
int ft_range(t_stack *a, int chunks, int *range)
{
	int max;
	int min;
	size_t i;

	min = a->data[0];
	max = a->data[0];
	i = 1;
	while (i != a->len)
	{
		if (stack_at(a, i) > max)
			max = stack_at(a, i);
		else if (stack_at(a, i) < min)
			min = stack_at(a, i);
		i++;
	}
	*range = ((max - min) + 1)/ chunks;
	return (min);
}

void sort_medium(t_stack *a, t_stack *b)
{
	int chunks;
	size_t i;
	int range;
	int min;
	int num;
	size_t len;
	
	chunks = ft_sqrt(a->len);
	i = 0;
	min = ft_range(a, chunks, &range);
	num = 0;
	len = a->len;
	print_stack(a);
	while (num <= chunks)
	{
		while (i < len)
		{
			if (stack_at(a, 0) >= min && stack_at(a, 0) <= min + range)
				pushb(a, b);
			else
				rotatea(a);
			i++;
		}
		// print_stack(a);
		// print_stack(b);
		sort_simple(b);
		len -= b->len;
		while (b->len > 0)
		{
			pusha(a, b);
			rotatea(a);
		}
		// print_stack(a);
		// print_stack(b);
		num++;
		min += (range + 1);
		i = 0;
	}
	
	// print_stack(b);
}

// printf("%d", range);
