/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:07:44 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/21 17:07:45 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcount(char const *str, char s)
{
	size_t index;
	size_t count;

	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] != s)
			count++;
		while (str[index] != s && str[index + 1])
			index++;
		index++;
	}
	return (count);
}
