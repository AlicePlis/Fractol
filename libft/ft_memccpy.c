/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:16:14 by jsonja            #+#    #+#             */
/*   Updated: 2019/09/18 15:49:20 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t count)
{
	size_t				index;
	unsigned char		*s1;
	unsigned char		*s2;

	s1 = (unsigned char*)dest;
	s2 = (unsigned char*)src;
	index = 0;
	c = (unsigned char)c;
	while (count > index)
	{
		s1[index] = s2[index];
		if (s1[index] == c)
			return ((void*)(dest + index + 1));
		index++;
	}
	return (NULL);
}
