/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_spec.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/16 12:56:39 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/19 23:16:00 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPEC_H
# define FT_SPEC_H

# include <stdarg.h>

enum e_flags
{
	F_ALT = 1 << 0,
	F_ZERO = 1 << 1,
	F_LEFT = 1 << 2,
	F_BLANK = 1 << 3,
	F_SIGN = 1 << 4,
};

typedef struct s_spec
{
	unsigned int	flags;
	int				width;
	int				prec;
	char			conv;
}	t_spec;

void	parse_spec(const char **fmt, t_spec *spec, va_list *ap);

#endif
