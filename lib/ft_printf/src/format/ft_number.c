/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_number.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/16 12:56:39 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/19 23:17:31 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_format.h"
#include "../ft_spec.h"
#include "../ft_strutils.h"
#include "../ft_utils.h"
#include <stdint.h>

static void	fmt_number(t_output *o, const t_spec *s, t_nbfmt n)
{
	int			len;
	int			zeros;
	int			padding;

	len = umaxtostr(&o->buf, n.nb, n.digits) * !(s->prec == 0 && n.nb == 0);
	zeros = max_int(0, s->prec - len);
	padding = max_int(0, s->width - ((int)ft_strlen(n.prefix) + zeros + len));
	if (!(s->flags & F_LEFT) && (s->flags & F_ZERO) && s->prec == -1)
		zeros += padding;
	else if (!(s->flags & F_LEFT))
		o->tokens[o->n++] = token_repeat(' ', padding);
	if (n.prefix)
		o->tokens[o->n++] = token_span(n.prefix, (int)ft_strlen(n.prefix));
	o->tokens[o->n++] = token_repeat('0', zeros);
	o->tokens[o->n++] = token_span((o->buf + UINTMAX_BITS - len), len);
	if (s->flags & F_LEFT)
		o->tokens[o->n++] = token_repeat(' ', padding);
}

void	fmt_ptr(t_output *o, const t_spec *spec, va_list *ap)
{
	void	*ptr;
	t_nbfmt	nbfmt;

	ptr = va_arg(*ap, void *);
	nbfmt = (t_nbfmt){.prefix = "0x", .digits = HEX_DIGITS};
	if (!ptr)
		fmt_txt_padded(o, spec, "(nil)", 5);
	else
	{
		nbfmt.nb = (uintptr_t)ptr;
		fmt_number(o, spec, nbfmt);
	}
}

void	fmt_int(t_output *o, const t_spec *spec, va_list *ap)
{
	int		nb;
	t_nbfmt	nbfmt;

	nb = va_arg(*ap, int);
	nbfmt = (t_nbfmt){.prefix = NULL, .digits = DECIMAL_DIGITS};
	if (spec->flags & F_SIGN)
		nbfmt.prefix = "+";
	else if (spec->flags & F_BLANK)
		nbfmt.prefix = " ";
	if (nb < 0)
	{
		nbfmt.prefix = "-";
		nbfmt.nb = (uintmax_t)(-(unsigned)nb);
	}
	else
		nbfmt.nb = (uintmax_t)nb;
	fmt_number(o, spec, nbfmt);
}

void	fmt_uint(t_output *o, const t_spec *spec, va_list *ap)
{
	t_nbfmt	nbfmt;

	nbfmt = (t_nbfmt){NULL, DECIMAL_DIGITS, va_arg(*ap, unsigned int), };
	fmt_number(o, spec, nbfmt);
}

void	fmt_hex(t_output *o, const t_spec *spec, va_list *ap)
{
	unsigned int	nb;
	t_nbfmt			nbfmt;

	nb = va_arg(*ap, unsigned int);
	nbfmt = (t_nbfmt){.prefix = NULL, .nb = nb};
	if (spec->conv == 'x')
		nbfmt.digits = HEX_DIGITS;
	else if (spec->conv == 'X')
		nbfmt.digits = HEX_DIGITS_UPPER;
	if (spec->flags & F_ALT && nb)
	{
		if (spec->conv == 'x')
			nbfmt.prefix = "0x";
		if (spec->conv == 'X')
			nbfmt.prefix = "0X";
	}
	fmt_number(o, spec, nbfmt);
}
