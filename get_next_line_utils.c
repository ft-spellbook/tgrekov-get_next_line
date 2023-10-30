/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:23:41 by tgrekov           #+#    #+#             */
/*   Updated: 2023/10/30 03:46:37 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*strcpy_fixed_len(char *dst, const char *src,
				size_t start, size_t n);

/*
 *	Finds the first newline in string s and sets *len to its index + 1

 *	If no newline is found, sets *len to 0

 *	Returns *len
 */
size_t	find_line_end(char *s, size_t *len)
{
	*len = 0;
	if (!s)
		return (0);
	while (s[*len])
	{
		if (s[(*len)++] == '\n')
			return (*len);
	}
	return (*len = 0);
}

/*
 *	Allocates string s3 with the contents of s1, if it is not null,
 *	followed by the contents of s2, and frees s1, if it is not null

 *	Returns s3
 */
char	*strjoin_free_first(char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s3;

	if (!s2)
		return (0);
	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = malloc(s1_len + s2_len + 1);
	if (!s3)
		return (0);
	if (s1)
		free(strcpy_fixed_len(s3, s1, 0, s1_len + 1));
	strcpy_fixed_len(s3 + s1_len, s2, 0, s2_len + 1);
	return (s3);
}

/*
 *	Allocates string s2 containing first len characters from *s1

 *	Allocates string new_s1 containing remainder of *s1
 *	after first len characters, frees *s1, and sets *s1 to new_s1

 *	Returns s2
 */
char	*consume_and_resize(char **s1, size_t len)
{
	size_t	new_s1_len;
	char	*new_s1;
	char	*s2;

	if (!s1 || !*s1)
		return (0);
	s2 = malloc(len + 1);
	if (!s2)
		return (0);
	strcpy_fixed_len(s2, *s1, 0, len + 1);
	new_s1_len = ft_strlen(*s1 + len);
	new_s1 = malloc(new_s1_len + 1);
	if (!new_s1)
	{
		free(s2);
		return (0);
	}
	free(strcpy_fixed_len(new_s1, *s1, len, new_s1_len + 1));
	*s1 = new_s1;
	return (s2);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
 *	Copies exactly n - 1 characters from src + start to dst, and terminates dst

 *	Returns src
 */
static char	*strcpy_fixed_len(char *dst, const char *src,
				size_t start, size_t n)
{
	dst[--n] = '\0';
	if (src != dst)
	{
		while (n--)
			dst[n] = src[start + n];
	}
	return ((char *) src);
}
