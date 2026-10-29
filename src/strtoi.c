/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strtoi.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 18:03:45 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/29 14:58:03 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_isspace(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	ft_atoi(const char *str)
{
	int	total;
	int	sign;

	total = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		total = total * 10 + (*str++ - '0') * sign;
	return (total);
}

int	ft_strtoi(const char *s, int *status)
{
	int	total;
	int	sign;

	total = 0;
	sign = 1;
	*status = 0;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		if (sign == -1 && total < INT_MIN / 10 - (*s - '0'))
			break ;
		else if (total > INT_MAX / 10 + (*s - '0'))
			break ;
		total = total * 10 + (*s++ - '0') * sign;
	}
	if (*s)
		*status = -1;
	return (total);
}
 
int main(void)
{
	{
		int	status;
		int	res = ft_strtoi("2147483648", &status);
		ft_printf("[int: %d; status: %d]\n", res, status);
	}
}
