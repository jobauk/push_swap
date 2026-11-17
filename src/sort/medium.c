/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/11 15:24:34 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/17 17:43:42 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <stdio.h>

int	ft_sqrt(size_t nmbr)
{
    int		sqrt;
    size_t	uneven;

	sqrt = 0;
	uneven = 1;
    while (nmbr >= uneven) 
	{
        nmbr = nmbr - uneven;
        uneven = uneven + 2;
        sqrt = sqrt + 1;
    }
	return (sqrt);
}

int	ft_range(t_stack *a, int chunks, int *range)
{
	int		max;
	int		min;
	size_t	i;

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
	*range = (max - min) / chunks;
	return (min);
}

void	bubble_sort(t_stack *stack)
{
	size_t	i;
	size_t	j;
// static void	bubble_sort(t_stack *stack)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	if (!stack->len)
// 		return ;
// 	while (i++ < stack->len - 1)
// 	{
// 		j = 0;
// 		while (j++ < stack->len - 1)
// 		{
// 			if (stack_at(stack, 0) > stack_at(stack, 1))
// 				swapb(stack);
// 			rotateb(stack);
// 		}
// 		rotateb(stack);
// 	}
// }

void	fill_b(t_stack *a, t_stack *b, int min, int max)
{
	size_t	i;
	size_t len;
	
	i = 0;
	len = a->len;
	while (i < len)
	{
		if (stack_at(a, 0) >= min && stack_at(a, 0) <= max)
			pushb(a, b);
		else
			rotatea(a);
		i++;
	}
	i = 0;
}

// void sort_medium(t_bench *bench, t_stack *a, t_stack *b)
// {
// 	int		chunks;
// 	int		range;
// 	int		min;
// 	int		num;
// void	sort_medium(t_stack *a, t_stack *b)
// {
// 	int		chunks;
// 	int		range;
// 	int		min;
// 	int		num;
	
// 	chunks = ft_sqrt(a->len);
// 	min = ft_range(a, chunks, &range);
// 	num = 0;
// 	while (num <= chunks)
// 	{
// 		while (i < len)
// 		{
// 			if (stack_at(a, 0) >= min && stack_at(a, 0) <= min + range)
// 				bench->pb_ops += pushb(a, b);
// 			else
// 				bench->ra_ops += rotatea(a);
// 			i++;
// 		}
// 		// print_stack(a);
// 		// print_stack(b);
// 		sort_simple(bench, b);
// 		len -= b->len;
// 		fill_b(a, b, min, min + range);
// 		bubble_sort(b);
// 		while (b->len > 0)
// 		{
// 			bench->pa_ops += pusha(a, b);
// 			bench->ra_ops += rotatea(a);
// 		}
// 		num++;
// 		min += (range + 1);
// 	}
// }
// 	chunks = ft_sqrt(a->len);
// 	min = ft_range(a, chunks, &range);
// 	num = 0;
// 	while (num <= chunks)
// 	{
// 		fill_b(a, b, min, min + range);
// 		bubble_sort(b);
// 		while (b->len > 0)
// 		{
// 			pusha(a, b);
// 			rotatea(a);
// 		}
// 		num++;
// 		min += (range + 1);
// 	}
// }

