/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:21:50 by gmaia-pe          #+#    #+#             */
/*   Updated: 2023/10/23 20:31:54 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

# include <fcntl.j>
# include <stdlib.h>
# include <unistd.h>

//node of the linked list

typedef struct s_list
{
    char    *str_buf;       //string
    struct s_list *next;	//pointer to the next node of the string
}               t_list;