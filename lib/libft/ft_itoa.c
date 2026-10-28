/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:41:24 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 14:47:45 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

static int	calc_size(int n)
{
	size_t	size;

	size = 2;
	if (n < 0)
		size++;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	int		is_neg;
	int		size;
	char	*buf;

	is_neg = n < 0;
	size = calc_size(n);
	buf = malloc(size * sizeof(char));
	if (!buf)
		return (buf);
	buf[--size] = '\0';
	while (size-- > is_neg)
	{
		buf[size] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (is_neg)
		buf[0] = '-';
	return (buf);
}

// #include <stdio.h>
//
// int main() {
// 	printf("<%s>\n", ft_itoa(INT_MIN));
// 	printf("<%s>\n", ft_itoa(0));
// 	printf("<%s>\n", ft_itoa(INT_MAX));
// }
