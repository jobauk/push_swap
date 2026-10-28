/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaukes <jaukes@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:49:27 by jaukes            #+#    #+#             */
/*   Updated: 2026/10/14 12:50:10 by jaukes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <sys/types.h>

static ssize_t	ckd_mul(size_t a, size_t b)
{
	if (b && a > SIZE_MAX / b)
		return (-1);
	return (a * b);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	ssize_t	n;
	void	*ptr;

	n = ckd_mul(nmemb, size);
	if (n == -1)
		return (NULL);
	ptr = malloc(n);
	if (ptr)
		ft_memset(ptr, 0x0, n);
	return (ptr);
}
