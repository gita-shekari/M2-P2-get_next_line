/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:50:18 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/16 23:10:59 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stash_trim(char *stash, size_t index)
{
	size_t	j;
	char	*temp;

	j = 0;
	temp = malloc(ft_strlen(stash) + index + 1);
	if (!temp)
		return (NULL);
	while (stash[index])
		temp[j++] = stash[index++];
	temp[j] = '\0';
	free(stash);
	return (temp);
}

char	*extract_line(char *stash)
{
	char	*line;
	size_t	i;

	i = 0;
	line = malloc(ft_strlen(stash) + 1);
	if (!line)
	{
		free(stash);
		return (NULL);
	}
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*stash;
	ssize_t		bytesread;
	int			finished;

	finished = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!finished)
	{
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread <= 0)
			break ;
		buf[bytesread] = '\0';
		stash = ft_strjoin(stash, buf);
		if (buf[bytesread - 1] == '\n')
			finished = 1;
	}
	if (!stash[0])
		return (free(stash), NULL);
	line = extract_line(stash);
	stash = stash_trim(stash, ft_strlen(line));
	return (line);
}

// int main(void)
// {
// 	int fd = open("myfile.txt", O_RDONLY);
// 	char *line;
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
