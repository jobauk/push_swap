/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_text.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/16 12:56:39 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/20 12:09:04 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_spec.h"
#include "../ft_strutils.h"
#include "../ft_utils.h"

void	fmt_txt_padded(t_output *o, const t_spec *spec,
	const char *s, int len)
{
	int	padding;

	padding = max_int(0, spec->width - len);
	if (!(spec->flags & F_LEFT))
		o->tokens[o->n++] = token_repeat(' ', padding);
	o->tokens[o->n++] = token_span(s, len);
	if (spec->flags & F_LEFT)
		o->tokens[o->n++] = token_repeat(' ', padding);
}

void	fmt_txt(t_output *o, const t_spec *spec, va_list *ap)
{
	int			len;
	const char	*s;

	len = 1;
	s = &o->buf[0];
	if (spec->conv == 'c')
		o->buf[0] = (char)va_arg(*ap, int);
	else if (spec->conv == 's')
	{
		s = va_arg(*ap, char *);
		if (!s)
		{
			s = "(null)";
			len = 0;
			if (spec->prec == -1 || spec->prec >= 6)
				len = 6;
		}
		else if (spec->prec != -1)
			len = min_int(spec->prec, (int)ft_strlen(s));
		else
			len = (int)ft_strlen(s);
	}
	fmt_txt_padded(o, spec, s, len);
}

void	fmt_percent(t_output *o, const t_spec *spec, va_list *ap)
{
	t_spec	nspec;

	(void)ap;
	nspec = (t_spec){spec->flags, 0, -1, spec->conv};
	o->buf[0] = '%';
	fmt_txt_padded(o, &nspec, &o->buf[0], 1);
}
