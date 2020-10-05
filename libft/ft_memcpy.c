/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:50:07 by jsonja            #+#    #+#             */
/*   Updated: 2019/09/23 16:59:30 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t	index;

	if (!dest && !src)
		return (NULL);
	index = 0;
	while (count > 0)
	{
		((unsigned char*)dest)[index] = ((unsigned char*)src)[index];
		index++;
		count--;
	}
	return (dest);
}
