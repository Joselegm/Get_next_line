/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:35:36 by marvin            #+#    #+#             */
/*   Updated: 2024/06/14 10:35:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

char *ft_strchr(const char *s, int c)
{
    int i;
    char *ptr;
    
    i = 0;
    ptr = (char*)s;
    while (*ptr)
    {
        if (*ptr == c)
            return(ptr);
        ptr++;
    }
    if (*ptr == c)
        return(ptr);
    return (NULL);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    char *p;
    size_t i;
    size_t d;

    if (!s1 ||!s2)
        return(NULL);
    p = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)+1));
    if (p == NULL)
        return (NULL);
    i = 0;
    d = 0;
    while (s1[i] != '\0')
    {
        p[i] = s1[i];
        i++;
    }
    while (s2[d])
    {
        p[d + i] = s2[d];
        d++;
    }
    p[d + i] = '\0';
    return (p);
}

/*int main()
{
    int c;
    c = 'n';
    printf("%s\n", ft_strchr("hola", c));
    //printf("%s\n", strchr("hola", -279));
    return (0);
}*/

/*int main()
{
    char *s;
    int b;
    s = "cuarenta y dos";
    b = ft_strlen(s);
    printf("%i\n", b);
    printf("%lu\n", ft_strlen(s));
}*/