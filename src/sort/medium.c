/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/11 15:24:34 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/12 13:31:04 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <stdio.h>

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
int ft_range(t_stack *a, int chunks)
{
	int max;
	int min;
	size_t i;
	int range;

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
	range = ((max - min) + 1) / chunks;
	return (range);
}

void sort_medium(t_stack *a, t_stack *b, int argc)
{
	int chunks;
	int i;
	int range;

	chunks = ft_sqrt(argc);
	i = 0;
	range = ft_range(a, chunks);
	
}
