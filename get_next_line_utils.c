/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:54:36 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/16 22:58:06 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joinstr;
	size_t	len;
	size_t	i;

	if (!s1)
		s1 = ft_strdup("");
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joinstr = NULL;
	i = 0;
	joinstr = (char *)malloc(len);
	if (!joinstr)
		return (NULL);
	if (s1)
		ft_strlcpy(joinstr, s1, ft_strlen(s1) + 1);
	if (s2)
		ft_strlcat(joinstr, s2, len);
	free(s1);
	return (joinstr);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	i = 0;
	if (size <= (dest_size))
		return (size + src_size);
	while (src[i] != '\0' && (dest_size + i) < (size - 1))
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest_size + src_size);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	src_size = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_size);
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_size);
}

char	*ft_strdup(const char *s)
{
	int		size;
	int		i;
	char	*copy;

	i = 0;
	size = ft_strlen(s);
	copy = (char *)malloc(size + 1);
	if (!copy)
		return (0);
	while (i < size + 1)
	{
		copy[i] = s[i];
		i ++;
	}
	return (copy);
}
