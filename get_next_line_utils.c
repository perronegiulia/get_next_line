/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:38:28 by giulia            #+#    #+#             */
/*   Updated: 2024/01/15 18:45:38 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Retorna uma substring contendo os caracteres até a quebra de linha ('\n')
char	*strdup_tilln(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	// Aloca memória para a substring e a preenche
	res = (char *)malloc(sizeof(char) * i + 1);
	res[i] = 0;
	while (i-- > 0)
		res[i] = str[i];
	return (res);
}

// Move os caracteres após a quebra de linha ('\n') para o início do buffer
void	strcpy_fromn(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	j = 0;
	while (str[i])
		str[j++] = str[i++];
	while (str[j])
		str[j++] = 0;
}

// Calcula o comprimento da string (semelhante à função padrão strlen)
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

// Encontra a primeira ocorrência do caractere c na string s
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (0);
}

// Concatena duas strings alocando memória suficiente para a nova string
char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		h;
	int		s1len;
	int		s2len;

	// Calcula o comprimento das duas strings
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	// Aloca memória para a nova string
	res = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!res)
		return (NULL);
	i = 0;
	h = 0;
	// Copia a primeira string para a nova string
	while (h < s1len)
		res[i++] = s1[h++];
	h = 0;
	// Copia a segunda string para a nova string
	while (h < s2len)
		res[i++] = s2[h++];
	res[i] = 0;
	// Libera a memória das strings originais
	free(s2);
	free(s1);
	// Retorna a nova string
	return (res);
}
