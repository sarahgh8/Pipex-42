/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:52:11 by sghunmin          #+#    #+#             */
/*   Updated: 2024/09/07 11:52:13 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	how_many_words(char const *s, char c)
{
	size_t	num_of_words;
	size_t	j;

	num_of_words = 0;
	j = 0;
	while (s[j] == c)
		j++;
	while (s[j])
	{
		if ((!j || s[j - 1] == c) && (s[j] != c))
			num_of_words++;
		j++;
	}
	return (num_of_words);
}

static size_t	size_of_word(char const *s, char c, size_t i)
{
	size_t	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

static char	*alloc_cpy(char *s, char c, t_intialVal *var)
{
	char	*res;
	size_t	i;

	i = 0;
	var->word_size = size_of_word(s, c, var->i);
	res = malloc((var->word_size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s[var->i] && s[var->i] != c)
		res[i++] = s[var->i++];
	res[i] = '\0';
	return (res);
}

static void	mem_free(char **res, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	t_intialVal		var;

	var.i = 0;
	var.j = 0;
	res = malloc((how_many_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[var.i])
	{
		if (s[var.i] != c)
		{
			res[var.j] = alloc_cpy((char *)s, c, &var);
			if (!res[var.j])
			{
				mem_free(res, var.j);
				return (NULL);
			}
			var.j++;
		}
		else
			var.i++;
	}
	res[var.j] = NULL;
	return (res);
}
// int main ()
// {
//     char **res;
//     size_t i;

//     res = ft_split("hellos!  sarah   kkkk g l@#$(:)^*     ",' ');
//     i = 0;
//     while(res[i])
//     {
//         printf("%s\n", res[i]);
//         i++;
//     }
//     return (0);
// }
