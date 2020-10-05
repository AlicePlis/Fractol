/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:18:47 by jsonja            #+#    #+#             */
/*   Updated: 2019/10/15 15:37:50 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	size_t	i;
	size_t	size;
	char	*s;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_nbrlen(n);
	if (!(s = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	s[size] = 0;
	if (n < 0)
	{
		s[i] = '-';
		i++;
		n *= -1;
	}
	while (i < size--)
	{
		s[size] = (n % 10) + 48;
		n /= 10;
	}
	return (s);
}
