/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 23:26:42 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/26 15:52:31 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "libft.h"
#include "ft_printf.h"
#include "sort.h"
#include <stdio.h>

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
		else if (opts.strat == S_ADAPTIVE)
			sort_adaptive(&ctx);
	}
	bench.real_strat = opts.strat;
	if (opts.is_bench)
		print_bench_results(&bench);
	stack_free(&a);
	stack_free(&b);
}
