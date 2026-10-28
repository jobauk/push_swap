/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 12:59:43 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/10/28 19:06:42 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum e_flag
{
	FLAG_NONE,
	FLAG_SIMPLE,
	FLAG_MEDIUM,
	FLAG_COMPLEX,
	FLAG_ADAPTIVE,
	FLAG_BENCH,
}	t_flag;

typedef enum e_strategy
{
	STRAT_NONE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE,
}

typedef struct s_opts
{
	t_strategy	strat;
	int			is_bench;
}	t_opts;

#endif
