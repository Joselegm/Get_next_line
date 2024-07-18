/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joselegm <joselegm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:56:01 by joselegm          #+#    #+#             */
/*   Updated: 2024/07/18 17:15:03 by joselegm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char *ft_readline(char *str)
{
    int i;
    char *new_line;
    
    if (!str || !str[0])
        return(NULL);
    i = 0;
    while (str[i] && str[i] != "\n")
        i++;
    if (str[i] == "\n")
        i++;
    new_line = (char *)malloc(sizeof(char) * i + 1);
    if (!new_line)
        return(NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        new_line[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
        new_line[i++] = '\n';
    new_line[i] = '\0';
    return (new_line);
}
char *ft_new_line(char *str1)
{
    int i;
    int k;
    char * new_file;
    
    i = 0;
    while (str1[i] && str1[i] != '\n')
        i++;
    if (!str1[i])
    {
        free(str1);
        return (NULL);
    }
    i += (str1[i] == '\n');
    new_file = (char *)malloc(sizeof(char) * (ft_strlen(str1) -i + 1));
    if (!new_file)
        return (NULL);
    k = 0;
    while (str1[i + k])
    {
        new_file[k] = str1[i + k];
        k++;
    }
    new_file[k] = '\0';
    free (str1);
    return (new_file);
}
char *get_next_line(int fd)
{
    int count;
    char *newline;
    static char *buff;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    count = 1;
    newline = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!newline)
        return (NULL);
    while (!ft_strchr(buff, '\n') && newline != 0)
    {
        count = read(fd, newline, BUFFER_SIZE);
        if (count == -1)
        {
            free(newline);
            return (NULL);
        }
        newline[count] = '\0';
        buff = ft_strjoin(buff, newline);
    }
    free(newline);
    newline = ft_readline(buff);
    buff = newline;
    return (newline);
}