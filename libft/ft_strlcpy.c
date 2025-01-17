/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:43:51 by sghunmin          #+#    #+#             */
/*   Updated: 2024/08/31 13:19:10 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*p1;

	p1 = (char *)src;
	i = 0;
	if (size == 0)
		return (ft_strlen(p1));
	while (p1[i] && i < size - 1)
	{
		dst[i] = p1[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(p1));
}
// int main()
// {
// 	char dst[20];
// 	//ft_strlcpy(dst, "lorem ipsum dolor sit amet", 0);
// 	printf("%ld\n", ft_strlcpy(dst, "lorem ipsum 0000000000000000000000", 3));
// 	return (0);
// }
