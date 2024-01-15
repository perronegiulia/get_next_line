/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:46:10 by gmaia-pe          #+#    #+#             */
/*   Updated: 2024/01/15 18:52:00 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Implementação própria da função strdup_tilln, que duplica a string até encontrar um caractere de nova linha
char	*strdup_tilln(char *str)
{
	int		i;
	char	*res;

    // Encontra a posição da próxima quebra de linha ou o final da string
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
    
    // Se encontrou uma quebra de linha, avança o índice
	if (str[i] == '\n')
		i++;
    
    // Aloca memória para a substring e o caractere nulo
	res = (char *)malloc(sizeof(char) * i + 1);
	res[i] = 0;
    
    // Copia a substring
	while (i-- > 0)
		res[i] = str[i];
    
    // Retorna a substring
	return (res);
}

// Implementação própria da função strcpy_fromn, que copia a string a partir da próxima linha
void	strcpy_fromn(char *str)
{
	int	i;
	int	j;

    // Encontra a posição da próxima quebra de linha ou o final da string
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
    
    // Se encontrou uma quebra de linha, avança o índice
	if (str[i] == '\n')
		i++;
    
    // Inicializa j para 0
	j = 0;
    
    // Copia a string a partir da próxima linha
	while (str[i])
		str[j++] = str[i++];
    
    // Preenche o restante com zeros
	while (str[j])
		str[j++] = 0;
}

// Implementação própria da função strlen
size_t	ft_strlen(const char *s)
{
	size_t	i;

    // Se s for nulo, retorna 0
	if (!s)
		return (0);
    
    // Inicializa i para 0
	i = 0;
    
    // Conta o número de caracteres até o final da string
	while (s[i])
		i++;
    
    // Retorna o tamanho da string
	return (i);
}

// Implementação própria da função strchr, que procura a primeira ocorrência de um caractere em uma string
char	*ft_strchr(const char *s, int c)
{
	int	i;

    // Inicializa i para 0
	i = 0;
    
    // Enquanto não chegou ao final da string
	while (s[i])
	{
        // Se encontrou o caractere, retorna o ponteiro para esse caractere em s
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
    
    // Se chegou ao final da string e o caractere é '\0', retorna o ponteiro para esse caractere em s
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
    
    // Se não encontrou o caractere, retorna nulo
	return (0);
}

// Implementação própria da função strjoin, que concatena duas strings e libera a memória das strings originais
char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		h;
	int		s1len;
	int		s2len;

    // Obtém os tamanhos das strings
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
    
    // Aloca memória para a string resultante
	res = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!res)
		return (NULL);
    
    // Inicializa os índices para percorrer as strings
	i = 0;
	h = 0;
    
    // Copia os caracteres da primeira string para a string resultante
	while (h < s1len)
		res[i++] = s1[h++];
    
    // Reinicializa h para 0
	h = 0;
    
    // Copia os caracteres da segunda string para a string resultante
	while (h < s2len)
		res[i++] = s2[h++];
    
    // Adiciona o caractere nulo ao final da string resultante
	res[i] = 0;
    
    // Libera a memória das strings originais
	free(s2);
	free(s1);
    
    // Retorna a string resultante
	return (res);
}
