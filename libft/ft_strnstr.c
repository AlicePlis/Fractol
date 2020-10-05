/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:43:32 by jsonja            #+#    #+#             */
/*   Updated: 2019/09/18 14:47:12 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	if (!(*needle))
		return ((char*)haystack);
	i = ft_strlen((char*)needle);
	while (*haystack && len-- >= i)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, i) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
