/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:41:24 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 14:47:45 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ' ');
	return (c);
}

// #include <stdio.h>

// int main() {
// 	printf("<%c>\n", ft_toupper('a'));
// 	printf("<%c>\n", ft_toupper(' '));
// 	printf("<%c>\n", ft_toupper('F'));
// 	printf("<%c>\n", ft_toupper('0'));
// }
