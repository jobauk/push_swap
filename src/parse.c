/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/26 15:44:59 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/26 15:47:08 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "libft.h"
#include <stdio.h>

int	parse_stack(t_stack *a, t_stack *b, char *argv[], int argc)
{
	int	i;
	int	status;

	i = 0;
	*a = stack_new((size_t)argc);
	*b = stack_new((size_t)argc);
	if (!a->data || !b->data)
		return (-1);
	while (i < argc)
	{
		stack_append(a, ft_strtoi(argv[i], &status));
		if (status == -1)
		{
			stack_free(a);
			stack_free(b);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	parse_flag(t_opts *opts, char *args)
{
	if (ft_memcmp(args, "bench", 6) == 0)
			opts->is_bench = 1;
	if (opts->strat == S_NONE)
	{
		if (ft_memcmp(args, "simple", 7) == 0)
			opts->strat = S_SIMPLE;
		else if (ft_memcmp(args, "medium", 7) == 0)
			opts->strat = S_MEDIUM;
		else if (ft_memcmp(args, "complex", 8) == 0)
			opts->strat = S_COMPLEX;
		else if (ft_memcmp(args, "adaptive", 9) == 0)
			opts->strat = S_ADAPTIVE;
		else
			return (-1);
	}
	return (0);
}

int	parse_flags(t_opts *opts, char *argv[], int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) != 0)
			break ;
		
		if (parse_flag(opts, argv[i] + 2) == -1)
			return (-1);
		else
			return (-1);
		i++;
	}
	return (i);
}