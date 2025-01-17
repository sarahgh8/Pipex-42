/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:52:43 by sghunmin          #+#    #+#             */
/*   Updated: 2024/09/07 11:52:45 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_of_digits(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	fill_the_array(size_t i, char *res, long _n)
{
	int	num;

	while (_n)
	{
		num = _n % 10;
		res[i] = num + '0';
		_n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	i;
	long	_n;

	_n = n;
	i = num_of_digits(n);
	res = malloc(i + 1);
	if (res == NULL)
		return (NULL);
	res[i--] = '\0';
	if (_n == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (_n < 0)
	{
		res[0] = '-';
		_n *= -1;
	}
	fill_the_array(i, res, _n);
	return (res);
}
// int main ()
// {
//     int n;

//     n = -85739873;
//     printf("%ld\n", num_of_digits(n));
//     printf("%s\n", ft_itoa(n));
//     return (0);
// }
