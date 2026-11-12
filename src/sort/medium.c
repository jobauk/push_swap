/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/11 15:24:34 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/12 14:11:50 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <stdio.h>
# include "push_swap.h"

int ft_sqrt(int argc)
{
    int nmbr = argc;
    int sqrt = 0;
    int uneven = 1;

    while (nmbr >= uneven) {
        nmbr = nmbr - uneven;
        uneven = uneven + 2;
        sqrt = sqrt + 1;
    }
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
		if (a->data[i] > max)
			max = a->data[i];
		else if (a->data[i] < min)
			min = a->data[i];
		i++;
	}
	*range = ((max - min) + 1) / chunks;
	return (min);
}

void sort_medium(t_stack *a, t_stack *b, int argc)
{
	int chunks;
	int i;
	int range;
	int min;

	chunks = ft_sqrt(argc);
	i = 0;
	min = ft_range(a, chunks, &range);
	while (i < argc)
	{
		if (a->data[i] >= min && a->data[i] <= (min + range) - 1)
			pusha(a, b);
		i++;
	}
	print_stack(b);
	print_stack(a);
	// min += range + 1;
}

// printf("%d", range);
