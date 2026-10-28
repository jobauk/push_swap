/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 17:51:41 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/30 17:03:08 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static int	str_has(const char *str, char c)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

static char	*strtrim_start(const char *s1, const char *set)
{
	while (str_has(set, *s1))
		s1++;
	return ((char *)s1);
}

static char	*strtrim_end(const char *s1, const char *set)
{
	size_t	len;
	size_t	size;
	char	*str;

	len = ft_strlen(s1);
	while (len && str_has(set, s1[len - 1]))
		len--;
	size = len + 1;
	str = malloc(size * sizeof(char));
	if (str)
		ft_strlcpy(str, s1, size);
	return (str);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	return (strtrim_end(strtrim_start(s1, set), set));
}

// #include <stdio.h>

// int main()
// {
// 	printf("%s\n", ft_strtrim("  & !*Hello, World*!!", " !&*"));
// }
