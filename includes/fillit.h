/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:34:43 by jkimberl          #+#    #+#             */
/*   Updated: 2019/09/23 18:19:40 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# include <stdlib.h>
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "./ft_find_solution.h"

/*
** adds.c
*/
int			smallest_square(int n);
int			find_max_x(char **array);
int			find_max_y(char **array);
int			find_min_y(char **array);
int			find_min_x(char **array);

/*
** change_input.c
*/
void		cut_array(char ****array);
void		change_symb(char ****array, int n);
void		move_tetr(char ****array, int n);

/*
** is_valid.c
*/

int			check_buf(char *buf);
int			is_valid(char *buf);

/*
** array_operations.c
*/

int			count_arrays(char ***array);
int			malloc_fill_array(char ***array, int i, char *buf);
void		ft_arraydel(char ***array);

/*
** main.c
*/

int			read_fill_extra(int fd, int i, char *buf, char ***array);
char		***read_file(int fd, int i);
char		***check_input(int fd);
int			main(int arc, char **argv);

#endif
