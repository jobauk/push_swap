/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 16:14:31 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/28 16:16:21 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #include <stdio.h>

// int main() {
// 	printf("%d", ft_isascii('a'));
// 	printf("%d", ft_isascii('D'));
// 	printf("%d", ft_isascii('0'));
// 	printf("%d", ft_isascii('3'));
// 	printf("%d", ft_isascii('.'));
// 	printf("%d", ft_isascii('\xff'));
// 	printf("%d", ft_isascii(255));
// }