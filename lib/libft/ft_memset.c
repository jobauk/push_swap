/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 16:24:32 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 10:48:02 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = (unsigned char)c;
	return (s);
}

// #include <string.h>
// #include <stdio.h>

// int main() {
// 	void *p = malloc(10);
// 	memset(p, 'Q', 10);
// 	((int *)p)[9] = '\0';

// 	printf("%s\n\n", (char *)p);

// 	int *s = ft_memset(p, 32425, 5);

// 	printf("%s\n\n", (char *)s);
// }
