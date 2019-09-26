/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:50:05 by jkimberl          #+#    #+#             */
/*   Updated: 2019/09/10 17:51:23 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *s1;
	t_list *s2;
	t_list *s3;

	if (!*begin_list)
		return ;
	if ((*begin_list)->next != 0)
	{
		s1 = *begin_list;
		s3 = 0;
		while (s1->next != 0)
		{
			s2 = s1->next;
			s1->next = s3;
			s3 = s1;
			s1 = s2;
		}
		*begin_list = s1;
		(*begin_list)->next = s3;
	}
}
