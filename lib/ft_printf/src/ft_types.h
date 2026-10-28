/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_types.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/16 12:56:39 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/19 23:28:34 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# include "ft_spec.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

# define UINTMAX_BITS (sizeof(uintmax_t) * CHAR_BIT)

typedef struct s_repeat
{
	char	c;
	int		n;
}	t_repeat;

typedef struct s_span
{
	const char	*s;
	int			len;
}	t_span;

typedef enum e_token_type
{
	TOK_REPEAT,
	TOK_SPAN,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	union
	{
		t_repeat	repeat;
		t_span		span;
	};
}	t_token;

typedef struct s_output
{
	char	buf[UINTMAX_BITS];
	t_token	tokens[8];
	int		n;
}	t_output;

typedef struct s_conv	t_conv;

typedef void			(*t_fmt)(t_output *, const t_spec *, va_list *);

struct s_conv
{
	char		conv;
	t_fmt		fmt;
};

#endif
