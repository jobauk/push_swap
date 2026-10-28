/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:41:24 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 14:47:45 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*buf;

	i = 0;
	buf = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!buf)
		return (buf);
	while (s[i])
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

// #include <stdio.h>

// char capitalize(unsigned int i, char c)
// {
// 	if (i == 0)
// 		return (ft_toupper(c));
// 	return (c);
// }

// int main() {
// 	printf("<%s>\n", ft_strmapi("hello, world", capitalize));
// }
