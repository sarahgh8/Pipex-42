/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:51:57 by sghunmin          #+#    #+#             */
/*   Updated: 2024/09/07 11:51:59 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void test(unsigned int i, char *s)
// {
//     if(i % 2 == 0)
//         *s = ft_toupper(*s);
// }
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		f(i, &s[i]);
		i++;
	}
}
// int main(int argc, char **argv)
// {
//     ft_striteri(argv[1], test);
//     printf("%s\n", argv[1]);
//     return (0);
// }
