/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:23:52 by tgrekov           #+#    #+#             */
/*   Updated: 2023/10/30 03:47:58 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "stdlib.h"
# include "unistd.h"

char	*get_next_line(int fd);
size_t	find_line_end(char *s, size_t *len);
char	*strjoin_free_first(char *s1, const char *s2);
char	*consume_and_resize(char **s1, size_t len);
size_t	ft_strlen(const char *str);

#endif
