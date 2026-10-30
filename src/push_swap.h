/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 12:59:43 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/10/30 16:05:34 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum e_strategy
{
	S_NONE,
	S_SIMPLE,
	S_MEDIUM,
	S_COMPLEX,
	S_ADAPTIVE,
}	t_strategy;

typedef struct s_opts
{
	t_strategy	strat;
	int			is_bench;
}	t_opts;

int	ft_strtoi(const char *s, int *status);

#endif
