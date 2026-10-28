/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/16 12:56:39 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/19 23:24:50 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_types.h"

t_token	token_repeat(char c, int n);

t_token	token_span(const char *s, int len);

int		max_int(int a, int b);

int		min_int(int a, int b);

#endif
