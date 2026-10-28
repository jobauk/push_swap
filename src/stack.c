/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 17:30:55 by jaukes        #+#    #+#                 */
/*   Updated: 2026/10/28 17:54:34 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stddef.h>
#include <stdlib.h>

t_stack stack_new(size_t init) {
	t_stack	stack;

	stack = (t_stack){.data = NULL, .len = 0, .cap = init};
	stack.data = malloc(sizeof(int) * init);
	return (stack);
}
