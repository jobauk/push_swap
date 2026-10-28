/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 17:51:41 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/30 17:03:08 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	calc_len(char const *s, char c)
{
	size_t	len;

	len = (*s && *s != c);
	while (*s)
	{
		len += (*s == c && s[1] && s[1] != c);
		s++;
	}
	return (len);
}

static char	*ft_strchrnul(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	return ((char *)s);
}

static void	*arr_free(char **arr, size_t len)
{
	while (len--)
		free(arr[len]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		len;
	char const	*start;
	char		**arr;

	i = 0;
	len = calc_len(s, c);
	arr = malloc((len + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (*s)
	{
		start = s;
		if (!*s || *s != c)
		{
			s = ft_strchrnul(start, c);
			arr[i] = ft_substr(start, 0, s - start);
			if (!arr[i++])
				return (arr_free(arr, i));
		}
		if (*s)
			s++;
	}
	arr[i] = NULL;
	return (arr);
}

// #include <stdio.h>
//
// int main() {
// 	ft_split("hello world test", ' ');
// 	ft_split("   hello world  test ", ' ');
// 	ft_split("abc", ',');
// 	ft_split("", ',');
// 	ft_split("xxxxxxxxhello!", 'x');
// }
