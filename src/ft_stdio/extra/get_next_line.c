/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:07:48 by martins           #+#    #+#             */
/*   Updated: 2024/09/15 20:07:49 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
#endif

static int		read_buffer(int fd, char *buffer, ssize_t *bytes);
static t_string	process_buffer(t_string line, char *buffer, size_t *position);
static t_string	append_newline(t_string line, size_t *position);

/**
 * @brief Returns a line from the file descriptor `fd`.
 *
 * Repeated calls to this function reads the text file pointed to by the file
 * descriptor, one line at a time.
 *
 * @param fd The file descriptor to read from.
 * @return The line read. NULL if there is nothing else to read or if an error
 * occured.
 */
char	*get_next_line(int fd)
{
	t_string		line;
	static char		buffer[BUFFER_SIZE + 1];
	static size_t	position;
	static ssize_t	bytes;

	if (BUFFER_SIZE <= 0 || fd == -1 || read(fd, buffer, 0) == -1)
		return (NULL);
	line = ft_stnnew_empty();
	if (!line)
		return (NULL);
	while (true)
	{
		if (position == 0 && !read_buffer(fd, buffer, &bytes))
			return (ft_stnfree(line), NULL);
		line = process_buffer(line, buffer, &position);
		if (!line)
			return (NULL);
		if (buffer[position] == '\n')
			return (append_newline(line, &position));
		if (!ft_stnisempty(line) && bytes < BUFFER_SIZE)
			break ;
		position = 0;
	}
	return (line);
}

static int	read_buffer(int fd, char *buffer, ssize_t *bytes)
{
	*bytes = read(fd, buffer, BUFFER_SIZE);
	if (*bytes <= 0)
		return (0);
	buffer[*bytes] = '\0';
	return (1);
}

static t_string	process_buffer(t_string line, char *buffer, size_t *position)
{
	size_t	len;

	len = ft_strcspn(buffer + *position, "\n");
	line = ft_stncat_size(line, buffer + *position, len);
	if (line)
		*position += len;
	return (line);
}

static t_string	append_newline(t_string line, size_t *position)
{
	line = ft_stncat_size(line, "\n", sizeof(char));
	if (line)
		(*position)++;
	return (line);
}
