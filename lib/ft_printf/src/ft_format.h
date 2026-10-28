/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_format.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/16 12:56:39 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/19 23:15:23 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_H
# define FT_FORMAT_H

# include "ft_types.h"
# include <stdint.h>

# define DECIMAL_DIGITS "0123456789"
# define HEX_DIGITS "0123456789abcdef"
# define HEX_DIGITS_UPPER "0123456789ABCDEF"

typedef struct s_nbfmt
{
	const char	*prefix;
	const char	*digits;
	uintmax_t	nb;
}	t_nbfmt;

void	fmt_txt_padded(t_output *o, const t_spec *spec, const char *s, int len);

void	fmt_txt(t_output *o, const t_spec *spec, va_list *ap);

void	fmt_percent(t_output *o, const t_spec *spec, va_list *ap);

void	fmt_ptr(t_output *o, const t_spec *spec, va_list *ap);

void	fmt_int(t_output *o, const t_spec *spec, va_list *ap);

void	fmt_uint(t_output *o, const t_spec *spec, va_list *ap);

void	fmt_hex(t_output *o, const t_spec *spec, va_list *ap);

#endif
