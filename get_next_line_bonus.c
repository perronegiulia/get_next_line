/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:44:54 by gmaia-pe          #+#    #+#             */
/*   Updated: 2024/01/15 18:45:04 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Função para liberar a memória alocada para content e res
void	*free_all(char **content, char **res, int mode)
{
    // Verifica se content é não nulo, então libera e define como nulo
	if (*content)
	{
		free(*content);
		*content = NULL;
	}

    // Verifica se res é não nulo e mode é verdadeiro, então libera e define como nulo
	if (*res && mode)
	{
		free(*res);
		*res = NULL;
	}
    // Retorna nulo
	return (NULL);
}

// Implementação própria da função calloc para alocar memória e inicializar com zeros
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	total;
	size_t	i;

	total = size * nmemb;

    // Verifica se o tamanho não é zero e se a divisão total/nmemb não é igual a size
    // (Evita overflow)
	if (nmemb != 0 && total / nmemb != size)
		return (NULL);

    // Aloca a memória
	res = malloc(total);
	if (!res)
		return (NULL);

    // Inicializa a memória com zeros
	i = 0;
	while (i < total)
		*((char *)res + i++) = 0;

	return (res);
}

// Função para obter o conteúdo do arquivo
char	*get_content(int fd, char **res, char **content)
{
	int	code;

    // Lê do arquivo para content com tamanho BUFFER_SIZE
	code = read(fd, *content, BUFFER_SIZE);
    
    // Se chegou ao final do arquivo
	if (code == 0)
	{
        // Se res não é nulo e res[0] é '\0', então libera e retorna nulo
		if (*res && *res[0] == '\0')
			return (free_all(content, res, 1));
        
        // Libera apenas o content e retorna res
		free_all(content, res, 0);
		return (*res);
	}

    // Enquanto houver algo para ler
	while (code > 0)
	{
        // Junta res com o conteúdo de content até a próxima quebra de linha
		*res = ft_strjoin(*res, strdup_tilln(*content));
        
        // Move o ponteiro de content para a posição após a última quebra de linha
		strcpy_fromn(*content);

        // Se houver uma quebra de linha em res, retorna res
		if (ft_strchr(*res, '\n'))
			return (*res);

        // Lê mais do arquivo para content
		code = read(fd, *content, BUFFER_SIZE);
	}

    // Se ocorreu um erro na leitura, libera e retorna nulo
	if (code == -1)
		return (free_all(content, res, 1));

    // Retorna res
	return (*res);
}

// Função principal para obter a próxima linha do arquivo
char	*get_next_line(int fd)
{
    // Array estático para armazenar o conteúdo de cada arquivo aberto
	static char	*content[MAX_FILES_OPENED];
	char		*res;

    // Verifica se fd é válido
	if (fd < 0 || fd >= MAX_FILES_OPENED)
		return (NULL);

    // Inicializa res como nulo
	res = NULL;

    // Se houver conteúdo para o arquivo
	if (content[fd])
	{
        // Obtém a linha até a próxima quebra de linha
		res = strdup_tilln(content[fd]);
        
        // Move o ponteiro de content para a posição após a última quebra de linha
		strcpy_fromn(content[fd]);
        
        // Se houver uma quebra de linha em res, retorna res
		if (ft_strchr(res, '\n'))
			return (res);
	}
    // Se não houver conteúdo para o arquivo
	else
        // Aloca memória para content[fd]
		content[fd] = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));

    // Se falhar a alocação de memória para content[fd], retorna nulo
	if (!content[fd])
		return (NULL);

    // Obtém o conteúdo do arquivo
	res = get_content(fd, &res, &content[fd]);
    
    // Retorna res
	return (res);
}
