/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:54:10 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 14:57:53 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return ((char *)last);
}

// #include <stdio.h>
//
// int main()
// {
// 	printf("<%s>\n", ft_strrchr("Hello, world", ','));
// 	printf("<%s>\n", ft_strrchr("Hello, world", 'x'));
// 	printf("<%s>\n", ft_strrchr("Hello, world", 'l'));
// 	printf("<\\%x>\n", *ft_strrchr("Hello, world", '\0'));
// }
