/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:01:16 by huates            #+#    #+#             */
/*   Updated: 2023/11/13 12:14:06 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_rtn = 0;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}

static void	signal_process(int signal)
{
	static int	i = 7;
	int			j;
	int			tmp;

	j = -1;
	tmp = 2;
	if (signal == SIGUSR1 && i > 0)
	{
		while (++j < i - 1)
			tmp *= 2;
		g_rtn += tmp;
	}
	else if (i == 0)
	{
		if (signal == SIGUSR1)
			g_rtn += 1;
		write(1, &g_rtn, 1);
		g_rtn = 0;
	}
	i--;
	if (i < 0)
		i = 7;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, signal_process);
	signal(SIGUSR2, signal_process);

	return (0);
}
