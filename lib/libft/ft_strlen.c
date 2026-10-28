/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 16:18:44 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/28 16:24:15 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s++)
		n++;
	return (n);
}

// #include <stdio.h>

// int main() {
// 	printf("%ld", ft_strlen(""));
// }