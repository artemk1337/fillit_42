/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchadwic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:42:51 by cchadwic          #+#    #+#             */
/*   Updated: 2019/09/22 17:42:35 by cchadwic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIND_SOLUTION_H
# define FT_FIND_SOLUTION_H

# include "libft.h"

char		**g_res;
int			ft_alg(char **field, char ***fig, int size);
int			ft_alg_extra(char **field, char ***fig, int size);
int			ft_put(char **field, int i, int k, char **fg);
void		ft_try_to_put(char ***mass, int count);
void		ft_print_mass(void);
int			ft_clean(char **m);
char		**ft_f_cpy(char **field);
char		**ft_create(int count);

#endif
