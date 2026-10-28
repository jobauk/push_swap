/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/16 12:56:39 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/19 23:17:56 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"
#include "ft_io.h"
#include "ft_types.h"
#include <unistd.h>

static const t_conv	g_formatters[] = {
{'%', fmt_percent},
{'c', fmt_txt},
{'s', fmt_txt},
{'p', fmt_ptr},
{'d', fmt_int},
{'i', fmt_int},
{'u', fmt_uint},
{'x', fmt_hex},
{'X', fmt_hex}
};

static void	fmt_field(t_output *o, t_spec *spec, va_list *ap)
{
	size_t	i;

	i = 0;
	while (i < sizeof(g_formatters) / sizeof(g_formatters[0]))
	{
		if (spec->conv == g_formatters[i].conv)
		{
			g_formatters[i].fmt(o, spec, ap);
			break ;
		}
		i++;
	}
}

static void	write_field(t_writer *w, t_output *o)
{
	int		i;
	t_token	token;

	i = 0;
	while (i < o->n)
	{
		token = o->tokens[i++];
		if (token.type == TOK_REPEAT)
			ft_putc_many(w, token.repeat.c, token.repeat.n);
		else if (token.type == TOK_SPAN)
			ft_write(w, token.span.s, (size_t)token.span.len);
	}
}

int	ft_printf(const char *fmt, ...)
{
	t_writer	writer;
	t_spec		spec;
	t_output	output;
	va_list		ap;

	writer = (t_writer){0};
	output = (t_output){0};
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			ft_putc(&writer, *fmt++);
		else
		{
			parse_spec(&fmt, &spec, &ap);
			fmt_field(&output, &spec, &ap);
			write_field(&writer, &output);
			output.n = 0;
		}
	}
	va_end(ap);
	if (writer.err || writer.total > INT_MAX)
		return (-1);
	return ((int)writer.total);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// {	ft_printf("\n[%#-8.5x]\n", 42);
// 	// 	printf("\n[%#-8.5x]\n\n", 42);
// 	// }

// 	// {	ft_printf("\n[%#08x]\n", 42);
// 	// 	printf("\n[%#08x]\n\n", 42);
// 	// }

// 	{	ft_printf("\n[%08.2d]\n", 42);
// 		printf("\n[%08.2d]\n\n", 42);
// 	}

// 	{	ft_printf("\n[%-8d]\n", 42);
// 		printf("\n[%-8d]\n\n", 42);
// 	}

// 	{	ft_printf("\n[%8d]\n", 42);
// 		printf("\n[%8d]\n\n", 42);
// 	}

// 	{	ft_printf("\n[%-8d]\n", 42);
// 		printf("\n[%-8d]\n\n", 42);
// 	}

// 	{	ft_printf("\n[%-8.5s]\n", "hello, world");
// 		printf("\n[%-8.5s]\n\n", "hello, world");
// 	}

// 	{	ft_printf("\n[%-8.5%]\n");
// 		printf("\n[%-8.5%]\n\n");
// 	}

// 	{	ft_printf("\n[%8.5%]\n");
// 		printf("\n[%8.5%]\n\n");
// 	}

// 	return (0);
// }
