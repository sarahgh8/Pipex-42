/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:29:11 by sghunmin          #+#    #+#             */
/*   Updated: 2024/09/01 16:29:14 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_rev(char *num, int i, int fd)
{
	while (i >= 0)
	{
		ft_putchar_fd(num[i], fd);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	unsigned int	nbr;
	char			num[11];

	i = 0;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			nbr = (unsigned int)(-n);
		}
		else
			nbr = (unsigned int)n;
		while (nbr > 0)
		{
			num[i++] = nbr % 10 + '0';
			nbr /= 10;
		}
		i--;
		print_rev(num, i, fd);
	}
}
/*int main ()
{
	ft_putnbr_fd(-2147483648, 1);
	ft_putnbr_fd(1234567890, 1);
	ft_putnbr_fd(0, 1);
	return (0);
}*/
