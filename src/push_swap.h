/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 12:59:43 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/10/28 14:51:52 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

enum e_strategy
{
	STRAT_NONE = -1,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE,
};

typedef struct s_stack
{
	int			*data;
	size_t		len;
}	t_stack;

int parse_args(enum e_strategy *strat, t_stack *stack, char *argv[], int argc);
int	main(int argc, char *argv[]);

#endif
