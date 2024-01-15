/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:20:09 by gmaia-pe          #+#    #+#             */
/*   Updated: 2024/01/15 17:20:09 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Função auxiliar para ler o conteúdo do arquivo e processar as linhas
static char	*read_content(int fd, char *res, char *content)
{
	int	read_return;

	// Lê o conteúdo do arquivo para o buffer 'content'
	read_return = read(fd, content, BUFFER_SIZE);
	while (read_return > 0)
	{
		// Concatena a linha processada ao resultado acumulado 'res'
		res = ft_strjoin(res, strdup_tilln(content));
		// Move o ponteiro no buffer 'content' para a próxima linha
		strcpy_fromn(content);
		// Se a linha processada contém uma quebra de linha, retorna o resultado
		if (ft_strchr(res, '\n'))
			return (res);
		// Lê mais conteúdo do arquivo para o buffer 'content'
		read_return = read(fd, content, BUFFER_SIZE);
	}
	// Caso tenha chegado ao final do arquivo, ajusta o buffer 'content'
	if (read_return == 0)
		content[0] = 0;
	// Caso ocorra um erro na leitura, libera o resultado acumulado e retorna NULL
	if (read_return == -1)
	{
		if (res)
			free(res);
		return (NULL);
	}
	// Retorna o resultado acumulado
	return (res);
}

// Função principal para obter a próxima linha do arquivo
char	*get_next_line(int fd)
{
	// Buffer estático para armazenar o conteúdo lido do arquivo
	static char	content[BUFFER_SIZE];
	// Ponteiro para o resultado acumulado
	char		*res;

	// Verifica se o descritor de arquivo é inválido
	if (fd < 0)
		return (NULL);
	// Inicializa o ponteiro de resultado
	res = NULL;
	// Se houver algo no buffer 'content'
	if (content[0])
	{
		// Lê a linha do buffer 'content' e atualiza o buffer
		res = strdup_tilln(content);
		strcpy_fromn(content);
		// Se a linha contém uma quebra de linha, retorna o resultado
		if (ft_strchr(res, '\n'))
			return (res);
	}
	// Lê mais conteúdo do arquivo e processa as linhas
	res = read_content(fd, res, content);
	// Retorna o resultado acumulado
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