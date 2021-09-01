/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:26:42 by agallipo          #+#    #+#             */
/*   Updated: 2021/09/01 21:09:02 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	t_var		variable;
	int			len;
	char *aux;
	aux = NULL;
	len = 0;
	if (BUFFER_SIZE < 1 || fd == -1 || read(fd, variable.buff, 0) == -1)
		return(NULL);
	variable.rd = read(fd, variable.buff, BUFFER_SIZE);
	if (variable.rd == -1 && !line)
		return (ft_strdup(""));
		//return (NULL);
	variable.buff[variable.rd] = '\0';
	if (!line)// && variable.rd != 0)
		line = ft_calloc(1,1);

	while (variable.rd > 0)
	{
		//printf("|2%p|\n", variable.buff);
		variable.chk = ft_strchr(variable.buff, '\n');
		variable.aux = ft_strjoin(line, variable.buff);
		free(line);
		line = ft_strdup(variable.aux);
        free(variable.aux);
		if (variable.chk != NULL)
			break ;
		variable.rd = read(fd, variable.buff, BUFFER_SIZE);
		variable.buff[variable.rd] = '\0';
	}
	//printf("|%p|\n", line);
	variable.chk = ft_strchr(line, '\n');
	//printf("--->%s---", variable.chk);
	if (variable.chk && variable.chk[0] != '\0')
	{
		if (BUFFER_SIZE != 1 && variable.chk[1] != '\0')
			aux = ft_strdup(variable.chk + 1);
		else
			aux = ft_strdup(variable.chk + 1);
	}
	if (line == NULL || line[0] == '\0')
	{
//		printf("Hola");
		free(line);
		return(NULL);
	}

	while(line[len] != '\n' && line[len] != '\0')
		len++;
	//printf("len = %d\n", len);
	//printf("excvbnm");
	//printf("--->%s---", aux);
	if (aux)
	{
		//printf ("1entro \n");
		//printf("--->%s---", aux);
		variable.aux = ft_substr(line, 0, (len + 1));
        free(line);
        line = NULL;
        line = ft_strdup(aux);
		free(aux);
		aux = NULL;
        return(variable.aux);
    }

	else
	{
		//printf ("1entro \n");
		//printf("%s", line);
		variable.aux = ft_strdup(line);
		free(line);
		line = NULL;
//		printf("Hola");
		return(variable.aux);
	}
	return(NULL);
}
/*
int	main()
{
	int 	fd;
	fd = open("/Users/agallipo/Desktop/GNL4/test/files/empty",O_RDONLY);

	char	*line;
	//line = "\0";


    while ((line = get_next_line(fd)) != 0)
    {
        printf("My line [%s]\n", line);
        free(line);
    }
	//free (line);
	//line = get_next_line(fd);
	//printf("My line [%s]\n", line);
	free (line);
	system("leaks a.out");
	return (0);
}
*/
