/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:48:29 by gmaia-pe          #+#    #+#             */
/*   Updated: 2024/01/15 18:48:32 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 21
# endif

# ifndef MAX_FILES_OPENED
#  define MAX_FILES_OPENED 1024
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// Declaração da função principal para obter a próxima linha do arquivo
char	*get_next_line(int fd);

// Declaração das funções utilitárias
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	strcpy_fromn(char *str);
char	*strdup_tilln(char *str);

// Declaração das funções adicionais
void	*free_all(char **content, char **res, int mode);
void	*ft_calloc(size_t nmemb, size_t size);

#endif