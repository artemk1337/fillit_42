/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:49:18 by jkimberl          #+#    #+#             */
/*   Updated: 2019/09/11 20:38:18 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static void		free_words(char **array, int n)
{
	int				i;

	i = 0;
	while (i < n)
	{
		free(array[i]);
		i++;
	}
}

unsigned int	k_splits(char const *s, char c)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 0;
	if (s[0] != c && s[0] != '\0')
		k++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			k++;
		i++;
	}
	return (k);
}

static void		split_spaces(const char *str, char **new, char c, int k)
{
	int				i;
	int				y;
	int				x;

	i = 0;
	y = 0;
	x = 0;
	while (x < k)
	{
		if (str[i] != c && str[i] != '\0')
			y++;
		else if (y != 0)
		{
			if (!(new[x] = ft_strsub(str, i - y, y)))
			{
				free_words(new, x);
				free(new);
				return ;
			}
			x++;
			y = 0;
		}
		i++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char			**new;
	unsigned int	k;

	if (!s)
		return (NULL);
	k = k_splits(s, c);
	if (!(new = (char **)malloc((k + 1) * sizeof(char *))))
		return (NULL);
	split_spaces(s, new, c, k);
	new[k] = NULL;
	return (new);
}
