/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 23:26:42 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/29 14:54:40 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "libft.h"
#include "ft_printf.h"

static int	parse_stack(t_stack *stack, char *argv[], int argc)
{
	(void)argv;
	*stack = stack_new((size_t)argc);
	if (!stack->data)
		return (-1);
	return (0);
}

static int	parse_flags(t_opts *opts, char *argv[], int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
			break ;
		if (opts->strat == S_NONE)
		{
			if (ft_memcmp(argv[i] + 2, "simple", 7) == 0)
				opts->strat = S_SIMPLE;
			else if (ft_memcmp(argv[i] + 2, "medium", 7) == 0)
				opts->strat = S_MEDIUM;
			else if (ft_memcmp(argv[i] + 2, "complex", 8) == 0)
				opts->strat = S_COMPLEX;
			else if (ft_memcmp(argv[i] + 2, "adaptive", 9) == 0)
				opts->strat = S_ADAPTIVE;
		}
		else if (ft_memcmp(argv[i] + 2, "bench", 6) == 0)
			opts->is_bench = 1;
		else
			return (-1);
		i++;
	}
	return (i);
}

int	parse_args(t_opts *opts, t_stack *stack, char *argv[], int argc)
{
	int	nflags;

	nflags = parse_flags(opts, argv, argc);
	if (nflags == -1 || opts->strat == S_NONE)
		return (-1);
	return (parse_stack(stack, argv + nflags, argc - nflags));
}

// int	main(int argc, char *argv[])
// {
// 	t_opts	opts;
// 	t_stack	stack;

// 	(void)argc;
// 	ft_printf("%d", parse_args(&opts, &stack, argv + 1, argc - 1));
// }
