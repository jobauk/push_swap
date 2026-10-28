/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kivan-ei <kivan-ei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/28 12:59:43 by kivan-ei      #+#    #+#                 */
/*   Updated: 2026/10/28 18:10:28 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

enum e_flag
{
	FLAG_NONE = 1 << 0,
	FLAG_SIMPLE = 1 << 1,
	FLAG_MEDIUM = 1 << 2,
	FLAG_COMPLEX = 1 << 3,
	FLAG_ADAPTIVE = 1 << 4,
	FLAG_BENCH = 1 << 5,
};

#endif
