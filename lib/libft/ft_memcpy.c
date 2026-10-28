/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 10:51:51 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 13:56:38 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>

// int main() {
// 	char src[] = "Hello\0 World";
// 	char dest[25];

// 	printf("%s", src);
// 	printf("%s\n", src + 6);

// 	ft_memcpy(dest, src, 8);

// 	printf("%s", dest);
// 	printf("%s", dest + 6);
// }
