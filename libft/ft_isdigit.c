/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:03:43 by sghunmin          #+#    #+#             */
/*   Updated: 2024/08/27 16:07:33 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

//#include <stdlib.h>

int	ft_isdigit(int c)
{
	return ((c >= 48 && c <= 57));
}
/*int main (int argc, char **argv)
{
	printf("%d", ft_isdigit(atoi(argv[1])));
	(void)argc;
	return (0);
}*/
