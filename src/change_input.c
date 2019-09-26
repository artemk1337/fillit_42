/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:37:56 by jkimberl          #+#    #+#             */
/*   Updated: 2019/09/23 16:30:56 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** сдвигаем тетрамино в левый верхний угол.
** для этого находим минимальное значение X и Y занятых клеток,
** после чего просто заменяем значения для занятых клеток на
** пустые, а для x - min и y - min на заполненные.
*/

void		move_tetr(char ****array, int n)
{
	int		i;
	int		j;
	int		k;
	int		min_x;
	int		min_y;

	i = -1;
	while (++i < n)
	{
		min_x = find_min_x((*array)[i]);
		min_y = find_min_y((*array)[i]);
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
			{
				if ((*array)[i][j][k] == '#')
				{
					(*array)[i][j][k] = '.';
					(*array)[i][j - min_y][k - min_x] = '#';
				}
			}
		}
	}
}

/*
** заменяем символы # в массивах на заглавные буквы, учитывая
** номер массива.
** пустые клетки (точки) заменяем на нули (48 символ таблицы).
** просто потому что так решили.
*/

void		change_symb(char ****array, int n)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if ((*array)[i][j][k] == '#')
					(*array)[i][j][k] = 65 + i;
				else
					(*array)[i][j][k] = 48;
				k++;
			}
			j++;
		}
		i++;
	}
}

/*
** обрезаем массив по занятым клеткам, чтобы лишние нули не анализировать.
*/

void		cut_array(char ****array)
{
	int		i;
	int		j;
	int		k;
	int		max[2];

	i = -1;
	while ((*array)[++i])
	{
		max[0] = find_max_x((*array)[i]);
		max[1] = find_max_y((*array)[i]);
		j = -1;
		while ((*array)[i][++j])
			if (j > max[1])
				ft_strdel(&(*array)[i][j]);
			else
			{
				k = -1;
				while ((*array)[i][j][++k])
				{
					if (k > max[0] || j > max[1])
						(*array)[i][j][k] = '\0';
				}
			}
	}
}
