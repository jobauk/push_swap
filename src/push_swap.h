/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 12:59:43 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/11/17 16:08:03 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

typedef enum e_strategy
{
	S_NONE,
	S_SIMPLE,
	S_MEDIUM,
	S_COMPLEX,
	S_ADAPTIVE,
}	t_strategy;

typedef struct s_bench
{
	double		disorder;
	t_strategy	input_strat;
	t_strategy	real_strat;
	int			sa_ops;
	int			sb_ops;
	int			ss_ops;
	int			pa_ops;
	int			pb_ops;
	int			ra_ops;
	int			rb_ops;
	int			rr_ops;
	int			rra_ops;
	int			rrb_ops;
	int			rrr_ops;
}	t_bench;

typedef struct s_opts
{
	t_strategy	strat;
	int			is_bench;
}	t_opts;

int		ft_strtoi(const char *s, int *status);

void	print_stack(t_stack *stack);

void	print_bench_results(t_bench *bench);

#endif
