/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchadwic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:45:55 by cchadwic          #+#    #+#             */
/*   Updated: 2019/09/23 19:09:14 by cchadwic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**g_res;

int			ft_put(char **field, int i, int k, char **fg)
{
	int i1;
	int k1;

	i1 = -1;
	while (fg[++i1])
	{
		if (!(field[i1 + i]))
			return (0);
		k1 = -1;
		while (fg[i1][++k1])
			if (!(field[i1 + i][k1 + k]) ||
					(field[i1 + i][k1 + k] != '0' && fg[i1][k1] != '0'))
				return (0);
	}
	i1 = -1;
	while (fg[++i1])
	{
		k1 = -1;
		while (fg[i1][++k1])
			if (fg[i1][k1] != '0')
				field[i1 + i][k1 + k] = fg[i1][k1];
	}
	return (1);
}

int			ft_alg_extra(char **field, char ***fig, int size)
{
	int		i;
	int		k;
	int		err;
	char	**tmp_f;

	i = -1;
	while (++i < size)
	{
		k = -1;
		while (++k < size)
		{
			if (!(tmp_f = ft_f_cpy(field)))
				return (-1);
			if ((err = ft_put(tmp_f, i, k, fig[0])) == 1)
			{
				if ((err = ft_alg(tmp_f, &(fig[1]), size)) == 1)
					return (ft_clean(tmp_f) + 1);
				else if (err == -1)
					return (ft_clean(tmp_f) - 1);
			}
			err = ft_clean(tmp_f);
		}
	}
	return (0);
}

int			ft_alg(char **field, char ***fig, int size)
{
	int		i;

	if (!(fig[0]))
	{
		if (!(g_res = ft_f_cpy(field)))
			return (-1);
		return (1);
	}
	i = ft_alg_extra(field, fig, size);
	if (i == 1)
		return (1);
	else if (i == -1)
		return (-1);
	return (0);
}

void		ft_try_to_put(char ***fig, int count)
{
	char	**field;
	int		i;
	int		k;

	i = 0;
	g_res = (NULL);
	while (!g_res)
	{
		if (!(field = ft_create(count + i)))
			return ;
		if (ft_alg(field, fig, count + i) == -1)
		{
			k = ft_clean(field);
			return ;
		}
		k = ft_clean(field);
		i++;
	}
	ft_print_mass();
}
