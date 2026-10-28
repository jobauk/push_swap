/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:47:59 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 14:48:44 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ' ');
	return (c);
}

// #include <stdio.h>

// int main() {
// 	printf("<%c>\n", ft_tolower('a'));
// 	printf("<%c>\n", ft_tolower(' '));
// 	printf("<%c>\n", ft_tolower('F'));
// 	printf("<%c>\n", ft_tolower('0'));
// }
