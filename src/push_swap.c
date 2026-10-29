/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 23:26:42 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/29 12:54:01 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "libft.h"
#include "ft_printf.h"

static int parse_flag(t_opts *opts, const char *flag)
{
	if (!ft_strncmp(flag, "--", 2))
		return (0);
	if (ft_strncmp(flag, "--simple", ft_strlen(flag)) == 0)
		opts->strat = STRAT_SIMPLE;
	else if (ft_strncmp(flag, "--medium", ft_strlen(flag)) == 0)
		opts->strat = STRAT_MEDIUM;
	else if (ft_strncmp(flag, "--complex", ft_strlen(flag)) == 0)
		opts->strat = STRAT_COMPLEX;
	else if (ft_strncmp(flag, "--adaptive", ft_strlen(flag)) == 0)
		opts->strat = STRAT_ADAPTIVE;
	else if (ft_strncmp(flag, "--bench", ft_strlen(flag)) == 0)
		opts->is_bench = 1;
	else 
		return (-1);
	return (0);
}
int parse_stack(t_stack *stack, char *argv[], int argc)
{
	(void)argv;
	*stack = stack_new((size_t)argc);
	if (!stack->data)
		return (-1);
	return (0);
}
int parse_args(t_opts *opts, t_stack *stack, char *argv[], int argc)
{
	int i;
	
	i = 1;
	opts->strat = STRAT_NONE;
	opts->is_bench = 0;
	if (argc < 3)
		return (-1);
	if (parse_flag(opts, argv[i]) == -1)
		return (-1);
	if (parse_flag(opts, argv[++i]) == -1)
		return (-1);
	if (opts->strat == STRAT_NONE)
		return (-1);
	if (opts->is_bench == 1)
		i++;
	if (parse_stack(stack, argv + 1, argc) == -1)
		return (-1);
	return (0);
		
}
int	main(int argc, char *argv[])
{
	t_opts	opts;
	t_stack	stack;
	(void)argc;
	
	ft_printf("%d", parse_args(&opts, &stack, argv, argc));
	
}

// int parse_args(t_opts *opts, t_stack *stack, char *argv[], int argc)
// {
// 	int		i;
// 	t_flag	flag;

// 	// i = 1;
// 	flag = parse_flag(argv[i]);
// 	opts->strat = STRAT_NONE;
// 	if (argc < 3)
// 		return (-1);
// 	if (flag == FLAG_BENCH)
// 		opts->is_bench = 1;
// 	if (strncmp(argv[i + 1], "--", 2) == 0)
// 	{
// 		flag = parse_flag(argv[++i]);
// 		if ((opts->is_bench && flag != FLAG_BENCH) && flag != FLAG_NONE)
// 			opts->strat = flag;
// 	}
// 	if (opts->strat == STRAT_NONE)
// 		return (-1);
// 	if (parse_stack(stack, argv + 1, argc) == -1)
// 		return (-1);
// 	return (0);
// }	