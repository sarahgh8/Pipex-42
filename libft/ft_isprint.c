/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:02:35 by sghunmin          #+#    #+#             */
/*   Updated: 2024/08/27 17:08:58 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return ((c >= 32 && c <= 126));
}

/*int	main(int argc, char **argv)
{
	printf("%d", ft_isprint(atoi(argv[1])));
	(void)argc;
	return (0);
}*/
