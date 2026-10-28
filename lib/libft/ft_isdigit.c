/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 14:14:14 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/28 16:16:17 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// #include <stdio.h>

// int main() {
// 	printf("%d", ft_isdigit('a'));
// 	printf("%d", ft_isdigit('D'));
// 	printf("%d", ft_isdigit('0'));
// 	printf("%d", ft_isdigit('.'));
// }