/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bench.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/17 15:40:11 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/17 16:53:44 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

static void	print_disorder(double db)
{
	db *= 100;
	ft_putnbr_fd((int)db, STDERR_FILENO);
	ft_putchar_fd('.', STDERR_FILENO);
	ft_putnbr_fd((int)(db * 10) % 10, STDERR_FILENO);
	ft_putnbr_fd((int)(db * 100) % 10, STDERR_FILENO);
}

static void	print_strategy(t_bench *bench)
{
	ft_putstr_fd("[bench] strategy:  ", STDERR_FILENO);
	if (bench->input_strat == S_SIMPLE)
		ft_putstr_fd("Simple / ", STDERR_FILENO);
	else if (bench->input_strat == S_MEDIUM)
		ft_putstr_fd("Medium / ", STDERR_FILENO);
	else if (bench->input_strat == S_COMPLEX)
		ft_putstr_fd("Complex / ", STDERR_FILENO);
	else if (bench->input_strat == S_ADAPTIVE)
		ft_putstr_fd("Adaptive / ", STDERR_FILENO);
	if (bench->real_strat == S_SIMPLE)
		ft_putstr_fd("O(n²)", STDERR_FILENO);
	else if (bench->real_strat == S_MEDIUM)
		ft_putstr_fd("O(n√n)", STDERR_FILENO);
	else if (bench->real_strat == S_COMPLEX)
		ft_putstr_fd("O(n log n)", STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

static void	print_pushswap_ops(t_bench *bench)
{
	ft_putstr_fd("[bench] ", STDERR_FILENO);
	ft_putstr_fd("sa: ", STDERR_FILENO);
	ft_putnbr_fd(bench->sa_ops, STDERR_FILENO);
	ft_putstr_fd("  sb: ", STDERR_FILENO);
	ft_putnbr_fd(bench->sb_ops, STDERR_FILENO);
	ft_putstr_fd("  ss: ", STDERR_FILENO);
	ft_putnbr_fd(bench->ss_ops, STDERR_FILENO);
	ft_putstr_fd("  pa: ", STDERR_FILENO);
	ft_putnbr_fd(bench->pa_ops, STDERR_FILENO);
	ft_putstr_fd("  pb: ", STDERR_FILENO);
	ft_putnbr_fd(bench->pb_ops, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

static void	print_rotate_ops(t_bench *bench)
{
	ft_putstr_fd("[bench] ", STDERR_FILENO);
	ft_putstr_fd("ra: ", STDERR_FILENO);
	ft_putnbr_fd(bench->ra_ops, STDERR_FILENO);
	ft_putstr_fd("  rb: ", STDERR_FILENO);
	ft_putnbr_fd(bench->rb_ops, STDERR_FILENO);
	ft_putstr_fd("  rr: ", STDERR_FILENO);
	ft_putnbr_fd(bench->rr_ops, STDERR_FILENO);
	ft_putstr_fd("  rra: ", STDERR_FILENO);
	ft_putnbr_fd(bench->rra_ops, STDERR_FILENO);
	ft_putstr_fd("  rrb: ", STDERR_FILENO);
	ft_putnbr_fd(bench->rrb_ops, STDERR_FILENO);
	ft_putstr_fd("  rrr: ", STDERR_FILENO);
	ft_putnbr_fd(bench->rrr_ops, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

void	print_bench_results(t_bench *bench)
{
	int	total_ops;

	total_ops = bench->sa_ops + bench->sb_ops + bench->ss_ops + bench->pa_ops
		+ bench->pb_ops + bench->ra_ops + bench->rb_ops + bench->rr_ops
		+ bench->rra_ops + bench->rrb_ops;
	ft_putstr_fd("[bench] disorder:  ", STDERR_FILENO);
	print_disorder(bench->disorder);
	ft_putendl_fd("%", STDERR_FILENO);
	print_strategy(bench);
	ft_putstr_fd("[bench] total_ops: ", STDERR_FILENO);
	ft_putnbr_fd(total_ops, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	print_pushswap_ops(bench);
	print_rotate_ops(bench);
}
