/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:07:15 by jkimberl          #+#    #+#             */
/*   Updated: 2019/09/26 12:54:16 by cchadwic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** i передаётся исключительно ради сокращения одной строчки в функции.
** создаём массив на 27 двухмерных массива потому что мы знаем,
** что фигур максимум 26.
** считываем по 20 символов (4 строки по 5 символов, учитывая \n).
** проверяем количество тетрамино, считанные 20 символов и закидываем их
** в массив.
** если ошибка, то чистим массив и возвращаем NULL.
** если всё прошло успешно, то считываем один символ из файла.
** если мы не достигли конца файла, то считаный символ должен быть \n.
** следующему 2D массиву присваиваем NULL, чтобы знать где заканчивается 3D.
** в конце проверки на то что есть хотя бы 1 тетрамино и нет пустой строки end
*/

char	***read_file(int fd, int i)
{
	char	***array;
	int		ret;
	char	buf[21];

	i = 0;
	if (!(array = (char ***)malloc(sizeof(char **) * 27)))
		return (NULL);
	array[0] = NULL;
	while ((ret = read(fd, buf, 20)))
	{
		i = read_fill_extra(fd, i, buf, array);
		if (i == -1 || i > 26)
		{
			ft_arraydel(array);
			return (NULL);
		}
	}
	array[i] = NULL;
	if ((ret == 0 && buf[0] == '\n') || !(array[0]))
	{
		ft_arraydel(array);
		return (NULL);
	}
	return (array);
}

int		read_fill_extra(int fd, int i, char *buf, char ***array)
{
	int		ret;

	buf[20] = '\0';
	if (i > 25 || !(check_buf(buf)) || !(malloc_fill_array(array, i, buf)))
		return (-1);
	ft_strclr(buf);
	if (!(ret = read(fd, buf, 1)) || buf[0] == '\n')
		i++;
	else
		return (-1);
	return (i);
}

/*
** основная функция парсинга.
** в начале проверяет записали ли в массив всё что нужно было из файла.
** после это считаем число тетрамин.
** сдвигаем в верхний левый угол.
** проверяем на валидность через сравнение с оригинальным файлом.
** заменяем символы на буквы и нули.
** обрезаем лишнее.
*/

char	***check_input(int fd)
{
	char	***array;
	int		n;

	n = 0;
	if (!(array = read_file(fd, n)))
		return (NULL);
	n = count_arrays(array);
	move_tetr(&array, n);
	change_symb(&array, n);
	cut_array(&array);
	return (array);
}

/*
** проверяем сколько аргументов приняла наша программа. Должен быть один.
** открываем файл, который нам передали.
** Возможно, нужно проверка открытия файла.
** проверяем ввод.
** считаем наименьший квадрат, в который уместятся наши фигуры.
*/

int		main(int arc, char **argv)
{
	int		fd;
	char	***array;
	int		n;

	if (arc != 2)
	{
		ft_putstr("usage: [map]\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || !(array = check_input(fd)))
	{
		ft_putstr("error\n");
		return (0);
	}
	n = smallest_square(count_arrays(array));
	ft_try_to_put(array, n);
	return (0);
}
