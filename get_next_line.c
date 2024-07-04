/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joselegm <joselegm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:56:01 by joselegm          #+#    #+#             */
/*   Updated: 2024/07/04 19:19:01 by joselegm         ###   ########.fr       */
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
    new_line = (char *)malloc(sizeof(char) * i+1);
    if (!new_line)
        return(NULL);
    
    
}