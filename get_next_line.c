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

static char	*read_content(int fd, char *res, char *content)
{
	int	read_return;

	read_return = read(fd, content, BUFFER_SIZE);
	while (read_return > 0)
	{
		res = ft_strjoin(res, strdup_tilln(content));
		strcpy_fromn(content);
		if (ft_strchr(res, '\n'))
			return (res);
		read_return = read(fd, content, BUFFER_SIZE);
	}
	if (read_return == 0)
		content[0] = 0;
	if (read_return == -1)
	{
		if (res)
			free(res);
		return (NULL);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	content[BUFFER_SIZE];
	char		*res;

	if (fd < 0)
		return (NULL);
	res = NULL;
	if (content[0])
	{
		res = strdup_tilln(content);
		strcpy_fromn(content);
		if (ft_strchr(res, '\n'))
			return (res);
	}
	res = read_content(fd, res, content);
	return (res);
}

/*
int main(void) {
    int fd = open("test_file.txt", O_RDONLY);

    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char *line;
    int line_number = 1;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Linha %d: %s\n", line_number, line);
        free(line);
        line_number++;
    }

    close(fd);

    return 0;
}
*/