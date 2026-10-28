/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:41:24 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 14:47:45 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	ft_putnbr_fd_internal(int n, int fd)
{
	if (n >= 10 || n <= -10)
		ft_putnbr_fd_internal(n / 10, fd);
	write(fd, &"0123456789"[ft_abs(n % 10)], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	ft_putnbr_fd_internal(n, fd);
}

// #include <limits.h>
//
// int main() {
// 	ft_putnbr_fd(INT_MIN, STDOUT_FILENO);
// 	write(STDOUT_FILENO, "\n", 1);
// 	ft_putnbr_fd(0, STDOUT_FILENO);
// 	write(STDOUT_FILENO, "\n", 1);
// 	ft_putnbr_fd(INT_MAX, STDOUT_FILENO);
// 	write(STDOUT_FILENO, "\n", 1);
// }
