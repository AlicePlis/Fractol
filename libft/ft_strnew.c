/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:33:51 by jsonja            #+#    #+#             */
/*   Updated: 2019/09/23 15:20:06 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	index;

	index = 0;
	if (size + 1 == 0)
		return (NULL);
	if (!(new = ft_memalloc(size + 1)))
		return (NULL);
	while (index < size)
	{
		new[index] = '\0';
		index++;
	}
	return (new);
}
