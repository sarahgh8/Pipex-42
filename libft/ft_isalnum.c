/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:08:51 by sghunmin          #+#    #+#             */
/*   Updated: 2024/08/27 16:19:28 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

//#include <stdlib.h>

int	ft_isalnum(int c)
{
	return (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) || (c >= 48
			&& c <= 57));
}
/*int main (int argc, char **argv)
{
	printf("%d", ft_isalnum(atoi(argv[1])));
	(void)argc;
	return (0);
}*/
