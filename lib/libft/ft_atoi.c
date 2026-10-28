/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 17:07:34 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 17:39:25 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// int main() {
// 	printf("[%d, %d]\n", ft_atoi("-2147483649"), atoi("-2147483649"));
// 	printf("[%d, %d]\n", ft_atoi("-2147483648"), atoi("-2147483648"));
// 	printf("[%d, %d]\n", ft_atoi("-2147483647"), atoi("-2147483647"));
// 	printf("[%d, %d]\n", ft_atoi("2147483648"), atoi("2147483648"));
// 	printf("[%d, %d]\n", ft_atoi("2147483647"), atoi("2147483647"));
// 	printf("[%d, %d]\n", ft_atoi("2147483646"), atoi("2147483646"));
// }
