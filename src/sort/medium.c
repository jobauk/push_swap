/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/11 15:24:34 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/11 16:48:38 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
void range(t_stack *a)
{
	int max;
	int min;
	size_t i;

	min = a->data[0];
	max = 0;
	i = 1;
	while (i != a->len)
	{
		if (a->data[i] > max && a->data[i] > min)
			max = a->data[i];
		else if (a->data[i] < min)
			min = a->data[i];
		i++;
	}
}

void sort_medium(t_stack *a, t_stack *b, int argc)
{
	int chunks;
	int i;

	chunks = ft_sqrt(argc);
	i = 0;
	
}
