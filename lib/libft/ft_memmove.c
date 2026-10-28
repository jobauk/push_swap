/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 12:24:25 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 13:56:48 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;

	if (!dest && !src)
		return (NULL);
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	tmp = dest;
	while (n--)
		((unsigned char *)tmp)[n] = ((unsigned char *)src)[n];
	return (dest);
}

// #include <string.h>

// int main(){
//   {
// 	char a[] = "Hello new world";

// 	char b[] = "Hello new world";

// 	memmove(a + 1, a, 5);
// 	puts(a);

// 	ft_memmove(b + 1, b, 5);
// 	puts(b);
//   }
//   {
// 	char a[] = "Hello new world";

// 	char b[] = "Hello new world";

// 	memmove(a, a + 1, 5);
// 	puts(a);

// 	ft_memmove(b, b + 1, 5);
// 	puts(b);
//   }
// }
