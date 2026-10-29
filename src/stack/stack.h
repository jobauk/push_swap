/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 17:44:30 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/28 17:44:30 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>

typedef struct s_stack
{
	int			*data;
	size_t		len;
	size_t		cap;
}	t_stack;

t_stack	stack_new(size_t init);

#endif
