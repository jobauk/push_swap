/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:58:07 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 15:54:22 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (n--)
	{
		if (!*us1 || !*us2 || *us1 != *us2)
			return (*us1 - *us2);
		us1++;
		us2++;
	}
	return (0);
}

// #include <stdio.h>

// int main() {
// 	printf("%d\n", ft_strncmp("hello world", "hello World", 12));
// 	printf("%d\n", ft_strncmp("hello world", "hello World", 5));
// 	printf("%d\n", ft_strncmp("\xff", "a", 1));
// 	printf("%d\n", ft_strncmp("", "", 1));
// 	printf("%d\n", ft_strncmp("", "World", 5));
// 	printf("%d\n", ft_strncmp("", "World", 0));

// 	printf("%d", (unsigned char)'\xff' - (unsigned char)'a');
// }
