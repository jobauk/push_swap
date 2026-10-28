/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_spec.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/16 12:56:39 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/19 23:15:51 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_spec.h"
#include <stdarg.h>

static int	parse_int(const char **fmt, va_list *ap)
{
	int	n;

	n = 0;
	if (**fmt == '*')
	{
		(*fmt)++;
		return (va_arg(*ap, int));
	}
	while (**fmt >= '0' && **fmt <= '9')
		n = n * 10 + *(*fmt)++ - '0';
	return (n);
}

static unsigned int	parse_flags(const char **fmt)
{
	unsigned int	flags;

	flags = 0;
	while (*++(*fmt))
	{
		if (**fmt == '#')
			flags |= F_ALT;
		else if (**fmt == '0')
			flags |= F_ZERO;
		else if (**fmt == '-')
			flags |= F_LEFT;
		else if (**fmt == ' ')
			flags |= F_BLANK;
		else if (**fmt == '+')
			flags |= F_SIGN;
		else
			break ;
	}
	return (flags);
}

void	parse_spec(const char **fmt, t_spec *spec, va_list *ap)
{
	spec->flags = parse_flags(fmt);
	spec->width = parse_int(fmt, ap);
	if (spec->width < 0)
	{
		spec->flags |= F_LEFT;
		spec->width = -spec->width;
	}
	spec->prec = -1;
	if (**fmt == '.')
	{
		(*fmt)++;
		spec->prec = parse_int(fmt, ap);
	}
	spec->conv = **fmt;
	if (**fmt)
		(*fmt)++;
}
