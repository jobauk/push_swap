/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_io.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/16 12:56:39 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/19 23:15:27 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>

static size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s && *s++)
		n++;
	return (n);
}

void	ft_write(t_writer *w, const char *buf, size_t n)
{
	ssize_t	ret;

	if (w->err)
		return ;
	ret = write(STDOUT_FILENO, buf, n);
	if (ret < 0 || (n > 0 && ret == 0))
		w->err = 1;
	else
		w->total += (size_t)ret;
}

void	ft_putc(t_writer *w, char c)
{
	ft_write(w, &c, 1);
}

void	ft_putc_many(t_writer *w, char c, int n)
{
	while (n-- > 0)
		ft_putc(w, c);
}

void	ft_puts(t_writer *w, const char *s)
{
	ft_write(w, s, ft_strlen(s));
}
