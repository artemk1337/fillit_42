/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution_extra.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchadwic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:41:32 by cchadwic          #+#    #+#             */
/*   Updated: 2019/09/22 17:42:14 by cchadwic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print_mass(void)
{
	int i;
	int k;

	i = -1;
	while (g_res[++i])
	{
		k = -1;
		while (g_res[i][++k])
			if (g_res[i][k] == '0')
				g_res[i][k] = '.';
	}
	i = 0;
	while (g_res[i])
	{
		ft_putstr(g_res[i++]);
		ft_putchar('\n');
	}
}

int			ft_clean(char **m)
{
	int i;

	i = 0;
	while (m[i])
		free(m[i++]);
	free(m);
	return (0);
}

static char	**ft_f_cpy_extra(char **field, char **tmp)
{
	int i;
	int k;

	i = -1;
	while (field[++i])
	{
		k = -1;
		while (field[i][++k])
			tmp[i][k] = field[i][k];
	}
	return (tmp);
}

char		**ft_f_cpy(char **field)
{
	int		i;
	int		k;
	char	**tmp;

	i = 0;
	while (field[i])
		i++;
	if (!(tmp = (char **)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	tmp[i] = (NULL);
	i = -1;
	while (field[++i])
	{
		k = 0;
		while (field[i][k])
			k++;
		if (!(tmp[i] = (char *)malloc(sizeof(char) * (k + 1))))
			return (NULL);
		tmp[i][k] = '\0';
	}
	return (ft_f_cpy_extra(field, tmp));
}

char		**ft_create(int count)
{
	int		i;
	int		k;
	char	**field;

	if (!count)
		return (NULL);
	i = 0;
	if (!(field = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while (i < (count))
	{
		k = 0;
		if (!(field[i] = (char *)malloc(sizeof(char) * (count + 1))))
			return (NULL);
		while (k < (count))
			field[i][k++] = '0';
		field[i][k] = '\0';
		i++;
	}
	field[i] = (NULL);
	return (field);
}
