/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:52:31 by sghunmin          #+#    #+#             */
/*   Updated: 2024/09/07 11:52:32 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	if (dest == NULL && src == NULL)
		return (NULL);
	p1 = (unsigned char *)src;
	p2 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		p2[i] = p1[i];
		i++;
	}
	return (dest);
}
