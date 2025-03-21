/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blgutier <blgutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:15:03 by blgutier          #+#    #+#             */
/*   Updated: 2025/02/26 20:36:26 by blgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdint.h>
#include <limits.h>

char	*extract_line(char *storage)
{
	int		len;
	char	*line;
	char	*newline_posiz;

	if (!storage || !*storage)
		return (NULL);
	newline_posiz = ft_strchr(storage, '\n');
	if (newline_posiz)
		len = newline_posiz - storage + 1;
	else
		len = ft_strlen(storage);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (--len >= 0)
		line[len] = storage[len];
	return (line);
}

char	*clean_storage(char *storage)
{
	int	i;
	int	remain_len;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		if (storage)
			free(storage);
		storage = NULL;
		return (NULL);
	}
	remain_len = ft_strlen(storage) - i;
	ft_memmove(storage, storage + i + 1, remain_len);
	storage[remain_len] = '\0';
	return (storage);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	copy = malloc(len * sizeof(char) + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*read_and_save(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;
	char	*temp;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(storage, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(storage), NULL);
		buffer[bytes_read] = '\0' ;
		if (!storage)
			storage = ft_strdup("");
		temp = ft_strjoin(storage, buffer);
		free(storage);
		storage = temp;
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[MAX_FD];
	char		*line;

	if (fd >= MAX_FD || fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	storage[fd] = read_and_save(fd, storage[fd]);
	if (!storage[fd])
	{
		storage[fd] = NULL;
		return (NULL);
	}
	line = extract_line(storage[fd]);
	storage[fd] = clean_storage(storage[fd]);
	return (line);
}
