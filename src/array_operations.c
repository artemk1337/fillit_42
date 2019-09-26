/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:45:05 by jkimberl          #+#    #+#             */
/*   Updated: 2019/09/23 15:53:11 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_arrays(char ***array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int			malloc_fill_array(char ***array, int i, char *buf)
{
	if (!(array[i] = (char **)malloc(sizeof(char *) * 5)))
		return (0);
	array[i + 1] = NULL;
	if (!(array[i][0] = ft_strsub(buf, 0, 4)))
		return (0);
	if (!(array[i][1] = ft_strsub(buf, 5, 4)))
		return (0);
	if (!(array[i][2] = ft_strsub(buf, 10, 4)))
		return (0);
	if (!(array[i][3] = ft_strsub(buf, 15, 4)))
		return (0);
	array[i][4] = NULL;
	return (1);
}

void		ft_arraydel(char ***array)
{
	int		i;
	int		j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			free(array[i][j]);
			j++;
		}
		free(array[i]);
		i++;
	}
	free(array);
}
