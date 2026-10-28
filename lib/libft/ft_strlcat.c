/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 13:57:18 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 18:22:05 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_cap(const char *str, size_t cap)
{
	size_t	n;

	n = 0;
	while (str[n] && cap--)
		n++;
	return (n);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	dest_len;
	size_t	src_len;

	n = 0;
	dest_len = ft_strlen_cap(dest, size);
	src_len = ft_strlen(src);
	if (size > dest_len)
		n = size - dest_len - 1;
	dest += dest_len;
	while (n && *src)
	{
		*dest++ = *src++;
		n--;
	}
	if (size > dest_len)
		*dest = '\0';
	return (dest_len + src_len);
}

// #include <stdio.h>
// #include <bsd/string.h>

// int main() {
// 	char dest1[7] = "1337 42";
// 	char src1[] = "Born to code";
// 	unsigned int len1 = ft_strlcat(dest1, src1, 7);
// 	printf("<%s> (%d)\n", dest1, len1);

// 	char dest2[4] = "";
// 	char src2[] = "";
// 	unsigned int len2 = ft_strlcat(dest2, src2, 10);
// 	printf("<%s> (%d)\n", dest2, len2);

// 	char dest3[5] = "";
// 	char src3[] = "hello";
// 	unsigned int len3 = ft_strlcat(dest3, src3, 4);
// 	printf("<%s> (%d)\n", dest3, len3);

// 	char dest4[] = "1337 42";
// 	char src4[] = "Born to code";
// 	unsigned int len4 = ft_strlcat(dest4, src4, 7);
// 	printf("<%s> (%d)\n", dest4, len4);

// 	char dest5[15] = "Test";
// 	char src5[] = "Test";
// 	unsigned int len5 = ft_strlcat(dest5, src5, 10);
// 	printf("<%s> (%d)\n", dest5, len5);
// }
