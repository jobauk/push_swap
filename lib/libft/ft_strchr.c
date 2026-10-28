/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:49:11 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 14:53:54 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
//
// int main()
// {
// 	printf("<%s>\n", ft_strchr("teste", 't' + 256));
// 	printf("<%s>\n", ft_strchr("teste", 'e'));
// 	printf("<%s>\n", ft_strchr("Hello, world", ','));
// 	printf("<%s>\n", ft_strchr("Hello, world", 'x'));
// 	printf("<%s>\n", ft_strchr("Hello, world", 'l'));
// 	printf("<\\%x>\n", *ft_strchr("Hello, world", '\0'));
// }
