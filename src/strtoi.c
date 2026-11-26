/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strtoi.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 18:03:45 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/26 14:14:34 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_strtoi(const char *s, int *status)
{
	int	total;
	int	sign;

	total = 0;
	sign = 1;
	*status = 0;
	if (*s == '-')
		sign = -1;
	s += (*s == '-' || *s == '+');
	while (*s >= '0' && *s <= '9')
	{
		if (total <= INT_MAX / 10 && total >= INT_MIN / 10)
			total *= 10;
		else
			break ;
		if (total >= INT_MIN + (*s - '0') && total <= INT_MAX - (*s - '0'))
			total += (*s++ - '0') * sign;
		else
			break ;
	}
	if (*s)
		*status = -1;
	return (total);
}
