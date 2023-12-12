/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:23:52 by tgrekov           #+#    #+#             */
/*   Updated: 2023/12/12 07:31:38 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line_bonus.h
 * @dontinclude get_next_line_bonus.h
 * @line /\* *********
 * @until /\* *********
 */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/**
 * @brief Set default BUFFER_SIZE if it is not defined at compile time
 */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/**
 * @brief Max open file descriptors per process
 */
# define MAX_FD 1024

# include "stdlib.h"
# include "unistd.h"

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *str);

#endif
