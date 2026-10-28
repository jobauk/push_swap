/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_io.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/16 12:56:39 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/19 23:15:43 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <stddef.h>

typedef struct s_writer
{
	size_t	total;
	int		err;
}	t_writer;

void	ft_write(t_writer *w, const char *buf, size_t n);

void	ft_putc(t_writer *w, char c);

void	ft_putc_many(t_writer *w, char c, int n);

void	ft_puts(t_writer *w, const char *s);

#endif
