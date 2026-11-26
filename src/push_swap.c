/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 23:26:42 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/26 14:13:15 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "libft.h"
#include "ft_printf.h"
#include "sort.h"
#include <stdio.h>

static int	parse_stack(t_stack *a, t_stack *b, char *argv[], int argc)
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

static int	parse_flags(t_opts *opts, char *argv[], int argc)
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

static double	compute_disorder(t_stack *stack)
{
	size_t	i;
	size_t	j;
	double	mistakes;
	double	total;
	
	i = 0;
	mistakes = 0;
	total = 0;
	while (i < stack->len)
	{
		j = i + 1;
		while (j < stack->len)
		{
			total++;
			if (stack_at(stack, i) > stack_at(stack, j))
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total);
}

void	print_stack(t_stack *stack)
{
	size_t	i;

	i = 0;
	fprintf(stderr, "[");
	while (i < stack->len)
	{
		fprintf(stderr, "%d", stack_at(stack, i));
		if (++i < stack->len)
			fprintf(stderr, ", ");
	}
	fprintf(stderr, "]\n");
}

int	main(int argc, char *argv[])
{
	int		nflags;
	t_bench	bench;
	t_opts	opts;
	t_stack	a;
	t_stack	b;
	t_context ctx;

	ctx = (t_context){.a = &a, .b = &b, .bench = &bench};
	bench = (t_bench){0};
	opts = (t_opts){0};
	nflags = parse_flags(&opts, ++argv, --argc);
	if (nflags == -1)
	{
		ft_printf("Error: invalid flag\n");
		return (1);
	}
	if (parse_stack(&a, &b, argv + nflags, argc - nflags) == -1)
	{
		ft_printf("Error: invalid sequence of numbers\n");
		stack_free(&a);
		stack_free(&b);
		return (1);
	}
	if (check_double(&a) == -1)
	{
		ft_printf("Error: duplicate values\n");
		stack_free(&a);
		stack_free(&b);
		return (1);
	}
	bench.disorder = compute_disorder(&a);
	bench.input_strat = opts.strat;
	if (argc > 1 && bench.disorder > 0.0)
	{
		if (opts.strat == S_NONE)
			opts.strat = S_ADAPTIVE;
		else if (opts.strat == S_SIMPLE)
			sort_simple(&ctx);
		else if (opts.strat == S_MEDIUM)
			sort_medium(&ctx);
		else if (opts.strat == S_COMPLEX)
			sort_complex(&ctx);
	}
	bench.real_strat = opts.strat;
	if (opts.is_bench)
		print_bench_results(&bench);
	stack_free(&a);
	stack_free(&b);
}
