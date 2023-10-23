/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:32:07 by gmaia-pe          #+#    #+#             */
/*   Updated: 2023/10/23 22:04:54 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_list(t_list **list, int fd)
{
	//nescessary to place the \0 -> "string\0"
	int		char_read;
	char	*buf;

	//scan line if \n exists
	while (!found_new_line(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
			return ;
									//10
		char_read = read(fd, buf, BUFFER_SIZE);
			//EOF	
		if (!char_read)
		{
			free (buf);
			return ;
		}
		buf[char_read] = '\0'
		//append the node
		append(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL; //behaves like a global variable with global scope
	char			*next_line;

	//fd are only positives || read gives -1 if there is problems on reading
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
										//checking if the file can be opened
										//if it is -1 i return NULL
		return (NULL);
	
	//create my list till i stumble into '\n'
	create_list(&list, fd);

	if (list == NULL)
		return (NULL);

	//fetch the linee from the list
	next_line = get_line(list);

	polish_list(&list);
	return (next_line);
}