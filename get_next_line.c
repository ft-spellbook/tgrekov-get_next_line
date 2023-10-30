/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:23:33 by tgrekov           #+#    #+#             */
/*   Updated: 2023/10/30 03:48:15 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 *	Reads data from file descriptor fd until a line ending or EOF is found

 *	Allocates a new string with the read data appended to the contents
 *	of *line_buf if it was not null, and frees *line_buf, if it was not null

 *	*line_buf is set to the pointer to the new string

 *	On error, *first_line_len is set to 0

 *	Otherwise, *first_line_len is set to the index position of
 *	the earliest newline + 1, if one exists, otherwise it is
 *	the length of *line_buf

 *	Returns *first_line_len
 */
static size_t	fill_line_buf(int fd, char **line_buf, size_t *first_line_len)
{
	char	*read_buf;
	ssize_t	read_len;

	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (*first_line_len = 0);
	read_len = BUFFER_SIZE;
	while (!find_line_end(*line_buf, first_line_len) && read_len == BUFFER_SIZE)
	{
		read_len = read(fd, read_buf, BUFFER_SIZE);
		if (read_len < 0)
		{
			free(read_buf);
			return (*first_line_len = 0);
		}
		read_buf[read_len] = '\0';
		*line_buf = strjoin_free_first(*line_buf, read_buf);
	}
	free(read_buf);
	if (read_len != BUFFER_SIZE && !*first_line_len)
		*first_line_len = ft_strlen(*line_buf);
	return (*first_line_len);
}

/*
 *	Sequentially read lines from file descriptor fd

 *	On error or EOF, returns null
 
 *	Otherwise returns a freeable, null-terminated string,
 *	including newline, if available
 */
char	*get_next_line(int fd)
{
	static char		*line_buf = 0;
	size_t			first_line_len;
	char			*out;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	fill_line_buf(fd, &line_buf, &first_line_len);
	if (!first_line_len)
	{
		if (line_buf)
			free(line_buf);
		return (line_buf = 0);
	}
	out = consume_and_resize(&line_buf, first_line_len);
	if (!out)
		free(line_buf);
	return (out);
}
