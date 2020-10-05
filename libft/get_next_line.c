/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:14:44 by jsonja            #+#    #+#             */
/*   Updated: 2019/10/15 16:42:30 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static t_list_m	*list_new(int fd)
{
	t_list_m *list;

	if (!(list = (t_list_m*)malloc(sizeof(t_list_m))))
		return (NULL);
	list->str = ft_strnew(0);
	list->fd = fd;
	list->next = NULL;
	return (list);
}

static t_list_m	*relevant_list(char **line, t_list_m **head, int fd)
{
	t_list_m	*list;

	if (fd < 0 || !line || !*head || BUFF_SIZE <= 0)
		return (NULL);
	list = *head;
	while (list)
	{
		if (list->fd == fd)
		{
			if (!list->str)
				list->str = ft_strnew(0);
			return (list);
		}
		list = list->next;
	}
	list = list_new(fd);
	if (!list)
		return (NULL);
	list->next = *head;
	*head = list;
	if (!list->str)
		list->str = ft_strnew(0);
	return (list);
}

static int		copy_line(char **line, int fd, char **str, int rd)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\0')
	{
		if (rd == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = *str;
		*str = NULL;
		return (1);
	}
	*line = ft_strsub(*str, 0, i);
	if (!*line)
		return (-1);
	tmp = *str;
	*str = ft_strdup(*str + i + 1);
	if (!*str)
		return (-1);
	free(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list_m	*head;
	t_list_m		*list;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				rd;

	rd = 0;
	if (!head)
		head = list_new(fd);
	if (!(list = relevant_list(line, &head, fd)))
		return (-1);
	if (!(ft_strchr(list->str, '\n')))
	{
		if ((rd = read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		buff[rd] = '\0';
		tmp = list->str;
		list->str = ft_strjoin(list->str, buff);
		if (!list->str)
			return (-1);
		free(tmp);
	}
	if (!ft_strlen(list->str))
		return (0);
	return (copy_line(line, fd, &list->str, rd));
}
