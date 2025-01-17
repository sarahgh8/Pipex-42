/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:17:45 by sghunmin          #+#    #+#             */
/*   Updated: 2024/08/29 18:17:48 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	if (n <= 0)
		return (0);
	while ((i < n - 1) && (p1[i] == p2[i]))
		i++;
	return ((unsigned char)p1[i] - (unsigned char)p2[i]);
}
/* int main ()
{
	char str1[] = "abc";
	char str2[] = "abc";
	size_t n = 7;
	printf("%d\n", ft_memcmp(str1, str2, n));
	return (0);
} */
