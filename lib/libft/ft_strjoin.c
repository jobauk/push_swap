/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 17:51:41 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 18:23:47 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (str)
	{
		ft_strlcpy(str, s1, s1_len + 1);
		ft_strlcpy(str + s1_len, s2, s2_len + 1);
	}
	return (str);
}

// #include <stdio.h>
//
// int main()
// {
// 	printf("<%s>\n", ft_strjoin("Hello, ", "World"));
// }
