/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 14:14:14 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 10:48:27 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// #include <stdio.h>

// int main() {
// 	printf("%d", ft_isalnum('a'));
// 	printf("%d", ft_isalnum('D'));
// 	printf("%d", ft_isalnum('0'));
// 	printf("%d", ft_isalnum('3'));
// 	printf("%d", ft_isalnum('.'));
// }