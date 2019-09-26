/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:33:19 by jkimberl          #+#    #+#             */
/*   Updated: 2019/09/23 17:28:32 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** расчёт наименьшего квадрата, в который влезут тетрамино.
** формула расчета:
** board starting size = sqrt(# of tetrominoes * 4 characters per tetromino)
** но поскольку мне лень считать приближенный корень я просто беру два
** соседних значения и смотрю окружают ли они то что под корнем
*/

int			smallest_square(int n)
{
	int		i;

	i = 1;
	while (i < 11)
	{
		if (i * i < n * 4 && (i + 1) * (i + 1) >= n * 4)
			return (i + 1);
		i++;
	}
	return (0);
}

/*
** четыре функции для расчета минимальных и максимальных Х и У занятых клеток
*/

int			find_max_x(char **array)
{
	int		i;
	int		j;
	int		max_x;

	max_x = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (array[i][j] != '0' && max_x < j)
				max_x = j;
			j++;
		}
		i++;
	}
	return (max_x);
}

int			find_max_y(char **array)
{
	int		i;
	int		j;
	int		max_y;

	max_y = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (array[i][j] != '0' && max_y < i)
				max_y = i;
			j++;
		}
		i++;
	}
	return (max_y);
}

int			find_min_x(char **array)
{
	int		i;
	int		j;
	int		min_x;

	min_x = 4;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (array[i][j] == '#' && min_x > j)
				min_x = j;
			j++;
		}
		i++;
	}
	return (min_x);
}

int			find_min_y(char **array)
{
	int		i;
	int		j;
	int		min_y;

	min_y = 4;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (array[i][j] == '#' && min_y > i)
				min_y = i;
			j++;
		}
		i++;
	}
	return (min_y);
}
