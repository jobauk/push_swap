/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 23:26:42 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/28 14:40:38 by kivan-ei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int parse_args(enum e_strategy *strat, t_stack *stack, char *argv[], int argc)
{
	int i;
	
	i = 1;
	strat = STRAT_NONE;
	while (i < argc)
	{
		
		if (ft_strcmp(argv[i], "--simple") && strat == STRAT_NONE)
			*strat = STRAT_SIMPLE;
		if (ft_strcmp(argv[i], "--medium") && strat == STRAT_NONE)
			*strat = STRAT_MEDIUM;
		if (ft_strcmp(argv[i], "--complex") && strat == STRAT_NONE)
			*strat = STRAT_COMPLEX;
		if (ft_strcmp(argv[i], "--adaptive") && strat == STRAT_NONE)
			*strat = STRAT_ADAPTIVE;
		i++;
	}
	return (-1);
}	

int	main(int argc, char *argv[])
{
	enum e_strategy *strat;
	t_stack *stack;
	
	parse_args(strat, stack, argv, argc);
}
