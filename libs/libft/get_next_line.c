/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:37:34 by xviladri          #+#    #+#             */
/*   Updated: 2025/03/23 20:37:20 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd, char *result)
{
	int		read_bytes;
	char	*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			return (free(buffer), result);
		buffer[read_bytes] = '\0';
		result = ft_strjoin_1(result, buffer);
	}
	free(buffer);
	return (result);
}

char	*line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc ((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*next_line(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	new_buffer = NULL;
	while (buffer[i] && (buffer[i] != '\n'))
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	new_buffer = malloc(ft_strlen_1(buffer) - i + 1);
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	new_buffer[j] = '\0';
	if (j == 0)
		return (free(new_buffer), NULL);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer = NULL;
	char			*new_line;

	new_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (buffer == NULL || !buffer)
		return (NULL);
	new_line = line(buffer);
	buffer = next_line(buffer);
	return (new_line);
}
