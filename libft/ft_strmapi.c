/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:51:40 by sghunmin          #+#    #+#             */
/*   Updated: 2024/09/07 11:51:42 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char test(unsigned int i, char c)
{
	if(i % 2 == 0)
		return (ft_toupper(c));
	else
		return (c);
} */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (i < ft_strlen(s))
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*int main (int argc, char **argv)
{
	char *res;
	res = ft_strmapi(argv[1], test);
	printf("%s\n", res);
	return (0);

} */
