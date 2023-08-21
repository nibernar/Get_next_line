/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:30:14 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/07 21:53:59 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <limits.h>

static char	*add_and_clean_buf(char *buffer, char *tmp);
static char	*ft_next_buff(char *buffer);
static char	*ft_select_line(char *buffer);
static char	*ft_read(int fd, char *buffer);
/**
 * @brief Returns a line read from a file descriptor.
 * 
 * @param fd The file descriptor.
 * @return A 'new' string.
 */
char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	str = ft_select_line(buffer[fd]);
	if (!str)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = ft_next_buff(buffer[fd]);
	return (str);
}

static char	*add_and_clean_buf(char *buffer, char *tmp)
{
	char	*temp;

	temp = ft_strjoin(buffer, tmp);
	free(buffer);
	return (temp);
}

static char	*ft_next_buff(char *buffer)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	len = -1;
	while (buffer[++len])
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = ft_calloc(sizeof(char), (len - i + 1));
	i++;
	if (!str)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	else
		while (i < len && buffer != NULL && buffer[i])
			str[j++] = buffer[i++];
	free (buffer);
	buffer = NULL;
	return (str);
}

static char	*ft_select_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = ft_calloc(sizeof(char), (i + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = buffer[i];
	return (str);
}

static char	*ft_read(int fd, char *buffer)
{
	char	*tmp;
	int		flag;

	tmp = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	flag = 1;
	while (flag > 0)
	{
		flag = read(fd, tmp, BUFFER_SIZE);
		if (flag == -1)
		{
			free(tmp);
			return (free(buffer), buffer = NULL, NULL);
		}
		if (flag < BUFFER_SIZE)
			return (end_of_file(buffer, tmp, flag));
		buffer = add_and_clean_buf(buffer, tmp);
		if (ft_strchr(buffer, '\n'))
		{
			free(tmp);
			break ;
		}
	}
	return (buffer);
}
