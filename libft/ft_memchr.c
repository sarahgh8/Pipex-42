/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:39:04 by sghunmin          #+#    #+#             */
/*   Updated: 2024/09/01 10:20:27 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (*str == (unsigned char)c)
		{
			return (str);
		}
		str++;
		i++;
	}
	return (NULL);
}
// // int main (int argc, char **argv)
// // {
// // 	printf("%s\n", (char *)ft_memchr(argv[1], ft_atoi(argv[2]),
// 			ft_atoi(argv[3])));
// // 	return (0);
// // }
