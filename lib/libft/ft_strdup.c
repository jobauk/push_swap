/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 17:51:41 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 18:23:47 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s);
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr)
		ft_strlcpy(ptr, s, (len + 1) * sizeof(char));
	return (ptr);
}
