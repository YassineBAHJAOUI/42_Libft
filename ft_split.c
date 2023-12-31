/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:23:12 by ybahjaou          #+#    #+#             */
/*   Updated: 2023/02/07 15:03:48 by ybahjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	count_words(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (str[++i])
		if (str[i] != c && (str[i + 1] == c || !str[i + 1]))
			count++;
	return (count);
}

static void	free_all(char **str, int l)
{
	while (l)
	{
		free(str[l]);
		l--;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		j;
	int		l;

	i = 0;
	l = -1;
	if (!s)
		return (NULL);
	p = (char **)malloc(sizeof (char *) * (count_words((char *)s, c) + 1));
	if (!p)
		return (NULL);
	while (++l < count_words((char *)s, c))
	{	
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		p[l] = ft_substr(s, j, i - j);
		if (!p[l])
			return (free_all(p, l), NULL);
	}
	return (p[l] = NULL, p);
}
/*
#include <stdio.h>
#include <string.h>

char    **ft_split(char *str, char *charset);

int main(int argc, char *argv[])
{
    char **result;
    int i;

    if (argc != 3)
    {
        printf("Usage: %s string charset\n", argv[0]);
        return (1);
    }
    result = ft_split(argv[1], argv[2]);
    for (i = 0; result[i]; i++)
        printf("%s\n", result[i]);
    return (0);
} */
