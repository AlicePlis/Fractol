/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:47:55 by jsonja            #+#    #+#             */
/*   Updated: 2019/09/20 16:19:12 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp1;
	t_list *tmp2;

	if (*alst && del)
	{
		tmp1 = *alst;
		while (tmp1)
		{
			tmp2 = tmp1;
			ft_lstdelone(&tmp1, del);
			tmp1 = tmp2->next;
		}
		*alst = NULL;
	}
}
