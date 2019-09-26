/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:39:22 by jkimberl          #+#    #+#             */
/*   Updated: 2019/09/10 17:49:22 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref)
{
	t_list	*new;

	if (!begin_list)
		return (NULL);
	new = begin_list;
	while (new != 0)
	{
		if (ft_memcmp(new->content, data_ref,
					(size_t)(sizeof(new->content) + 1)) == 0)
			return (&(*new));
		new = new->next;
	}
	return (NULL);
}
