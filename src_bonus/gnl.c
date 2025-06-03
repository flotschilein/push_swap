/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:20:33 by fbraune           #+#    #+#             */
/*   Updated: 2025/06/04 00:00:14 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	*get_line_buffer(char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static void	buffer_move(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i] != '\0')
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}

static int	read_to_buffer(int fd, char *buffer, char **temp)
{
	char	buffer_read[2];
	int		read_bytes;
	char	*temp_old;

	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(*temp, '\n'))
	{
		read_bytes = read(fd, buffer_read, 1);
		if (read_bytes == -1)
			return (free(*temp), *temp = NULL, buffer[0] = '\0', 0);
		if (read_bytes == 0)
			break ;
		buffer_read[read_bytes] = '\0';
		temp_old = *temp;
		*temp = ft_strjoin(temp_old, buffer_read);
		free(temp_old);
		if (!*temp)
			return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[2];
	char		*temp;

	if (fd < 0 || !line)
		return (-1);
	if (ft_strchr(buffer, '\n'))
	{
		*line = get_line_buffer(buffer);
		if (!*line)
			return (-1);
		buffer_move(buffer);
		return (1);
	}
	temp = ft_strdup(buffer);
	if (!temp)
		return (-1);
	buffer[0] = '\0';
	if (!read_to_buffer(fd, buffer, &temp))
		return (-1);
	*line = get_line_buffer(temp);
	if (!*line)
		return (free(temp), -1);
	if (temp[0])
		ft_strlcpy(buffer, temp + ft_strlen(*line), 2);
	return (free(temp), 1);
}
