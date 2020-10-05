/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:52:14 by jsonja            #+#    #+#             */
/*   Updated: 2019/09/18 14:14:56 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*w_free(char **s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
	return (NULL);
}

static size_t	w_len(char const *str, char s)
{
	size_t	len;

	len = 0;
	while (*str == s)
		str++;
	while (str[len] != s && str[len + 1])
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	k;
	size_t	j;
	size_t	n;
	char	**wrds;

	k = 0;
	n = 0;
	if (!s || !(wrds = (char**)malloc(sizeof(char*) * (ft_wcount(s, c) + 1))))
		return (NULL);
	while (k < ft_wcount(s, c))
	{
		if (!(wrds[k] = (char*)malloc(sizeof(char) * (w_len(&s[n], c) + 1))))
			return (w_free(wrds, k));
		j = 0;
		while (s[n] == c)
			n++;
		while (s[n] && s[n] != c)
			wrds[k][j++] = s[n++];
		wrds[k][j] = '\0';
		k++;
	}
	wrds[k] = NULL;
	return (wrds);
}
