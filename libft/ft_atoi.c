/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:56:09 by jsonja            #+#    #+#             */
/*   Updated: 2019/09/20 15:59:41 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	res;
	int			sign;

	sign = 1;
	res = 0;
	while (*str != '\0' && ft_isspace((int)*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0' && ft_isdigit((int)*str))
	{
		if (((res > 922337203685477580) || ((res == 922337203685477580) &&
											((*str - 48) > 7))) && sign == 1)
			return (-1);
		if (((res > 922337203685477580) || ((res == 922337203685477580) &&
											((*str - 48) > 8))) && sign == -1)
			return (0);
		res = (res * 10) + (*str - 48);
		str++;
	}
	return (res * sign);
}
