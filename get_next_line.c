/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giulia <giulia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:32:07 by gmaia-pe          #+#    #+#             */
/*   Updated: 2023/10/26 15:27:52 by giulia           ###   ########.fr       */
/*                  
mini printf
last week
ft_s                                                          */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_content(int fd, char *buf, char *content)
{
	int	read_return;

	read_return = read(fd, content, BUFFER_SIZE);
	while (read_return > 0)
	{
		buf = ft_strjoin(buf, strdupn(content));
		strcpyn(content);
		if (ft_strchr(buf, '\n'))
			return (buf);
		read_return = read(fd, content, BUFFER_SIZE);
	}
	if (read_return == 0)
		content[0] = 0;
	if (read_return == -1)
	{
		if (buf)
			free(buf);
		return (NULL);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	content[BUFFER_SIZE];
	char		*buf;

	if (fd < 0)
		return (NULL);
	buf = NULL;
	if (content[0])
	{
		buf = strdupn(content);
		strcpyn(content);
		if (ft_strchr(buf, '\n'))
			return (buf);
	}
	buf = ft_content(fd, buf, content);
	return (buf);
}

/*
int main()
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("test.txt", O_RDONLY);
	while (lines)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		if (line)
			free(line);
		else
			lines = 0;
	}
}
*/