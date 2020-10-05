/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:57:26 by jsonja            #+#    #+#             */
/*   Updated: 2019/09/24 14:20:30 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t res;

	i = 0;
	while (dst[i] && i < size)
		i++;
	res = i;
	while (src[i - res] && (i + 1) < size)
	{
		dst[i] = src[i - res];
		i++;
	}
	if (res < size)
		dst[i] = '\0';
	return (res + ft_strlen(src));
}
