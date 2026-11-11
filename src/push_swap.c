/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 23:26:42 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/11 15:27:10 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "libft.h"
#include "ft_printf.h"
#include "sort.h"

static int	parse_stack(t_stack *a, t_stack *b, char *argv[], int argc)
{
	int i;
	int status;

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

static int	parse_flags(t_opts *opts, char *argv[], int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) != 0)
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

void	print_stack(t_stack *stack)
{
	size_t	i;

	i = 0;
	ft_printf("[");
	while (i < stack->len)
	{
		ft_printf("%d", stack_at(stack, i));
		if (++i < stack->len)
			ft_printf(", ");
	}
	ft_printf("]\n");
}

int	main(int argc, char *argv[])
{
	int		nflags;
	t_opts	opts;
	t_stack	a;
	t_stack	b;

	opts = (t_opts){0};
	nflags = parse_flags(&opts, ++argv, --argc);
	if (nflags == -1 || opts.strat == S_NONE)
	{
		ft_printf("Error: invalid flag\n");
		return (1);
	}
	if (parse_stack(&a, &b, argv + nflags, argc - nflags) == -1)
	{
		ft_printf("Error: invalid sequence of numbers\n");
		return (1);
	}
	if (opts.strat == S_SIMPLE)
		sort_simple(&a);
	else if (opts.strat == S_MEDIUM)
		sort_medium(&a);
	stack_free(&a);
	stack_free(&b);
}
