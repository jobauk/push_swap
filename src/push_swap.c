/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 23:26:42 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/28 17:17:50 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

static enum e_strategy parse_flag(const char *flag)
{
	if (ft_strncmp(flag, "simple", ft_strlen(flag)) == 0)
		return (STRAT_SIMPLE);
	if (ft_strncmp(flag, "medium", ft_strlen(flag)) == 0)
		return (STRAT_MEDIUM);
	if (ft_strncmp(flag, "complex", ft_strlen(flag)) == 0)
		return (STRAT_COMPLEX);
	if (ft_strncmp(flag, "adaptive", ft_strlen(flag)) == 0)
		return (STRAT_ADAPTIVE);
	return (STRAT_NONE);
}

int parse_args(enum e_strategy *strat, t_stack *stack, char *argv[], int argc)
{
	int i;
	
	(void)stack;
	i = 1;
	*strat = STRAT_NONE;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
		{
			if (*strat == STRAT_NONE)
				*strat = parse_flag(argv[i] + 2);
			else
				return (-1);
		}
		i++;
	}
	if (*strat == STRAT_NONE)
		return (-1);
	return (0);
}	

int	main(int argc, char *argv[])
{
	enum e_strategy	strat;
	t_stack			stack;
	
	ft_printf("%d", parse_args(&strat, &stack, argv, argc));
}
