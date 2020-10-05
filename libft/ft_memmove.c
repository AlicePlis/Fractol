/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:21:32 by jsonja            #+#    #+#             */
/*   Updated: 2019/09/18 14:24:59 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char		*s1;
	unsigned char		*s2;
	size_t				index;

	if (count == 0)
		return (dest);
	index = 0;
	s1 = (unsigned char*)dest;
	s2 = (unsigned char*)src;
	if (s2 < s1)
	{
		index = 1;
		while (count >= index)
		{
			s1[count - index] = s2[count - index];
			index++;
		}
	}
	if (s2 > s1)
		while (count > index)
		{
			s1[index] = s2[index];
			index++;
		}
	return ((void*)dest);
}
