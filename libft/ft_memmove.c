/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:43:29 by sghunmin          #+#    #+#             */
/*   Updated: 2024/08/30 16:50:05 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	i = 0;
	if (p1 > p2)
	{
		while (n--)
			p1[n] = p2[n];
	}
	else
	{
		while (i < n)
		{
			p1[i] = p2[i];
			i++;
		}
	}
	return (dest);
}
