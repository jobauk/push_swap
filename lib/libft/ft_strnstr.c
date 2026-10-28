/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 16:19:30 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 17:07:18 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j])
			if (!little[++j])
				return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <bsd/string.h>
//
// int main() {
// 	printf(
// 		"<%s>\t\t<%s>\n",
// 		ft_strnstr("hello", "", 5),
// 		strnstr("hello", "", 5)
// 	);
// 	printf(
// 		"<%s>\t\t<%s>\n",
// 		ft_strnstr("hello", "", 0),
// 		strnstr("hello", "", 0)
// 	);
// 	printf(
// 		"<%s>\t<%s>\n",
// 		ft_strnstr("hello", "h", 0),
// 		strnstr("hello", "h", 0)
// 	);
// 	printf(
// 		"<%s>\t<%s>\n",
// 		ft_strnstr("abcabc", "abc", 6),
// 		strnstr("abcabc", "abc", 6)
// 	);
// 	printf(
// 		"<%s>\t\t<%s>\n",
// 		ft_strnstr("hello world", "world", 11),
// 		strnstr("hello world", "world", 11)
// 	);
// 	printf(
// 		"<%s>\t<%s>\n",
// 		ft_strnstr("hello world", "hello", 11),
// 		strnstr("hello world", "hello", 11)
// 	);
// }
