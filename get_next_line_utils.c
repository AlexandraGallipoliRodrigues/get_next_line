/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:03:36 by agallipo          #+#    #+#             */
/*   Updated: 2021/09/01 15:18:23 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(nmemb * size);
	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (ptr == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		(((unsigned char *)ptr)[i]) = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ptr = malloc(lens1 + lens2 + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ptr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (0);
}
char    *ft_strdup(const char *s1)
{
    char    *ptr;
    int        size;
    int        i;

    size = ft_strlen(s1);
    ptr = (char *)malloc(size + 1);
    if (!ptr)
        return (NULL);
    i = 0;
    while (size--)
    {
        ptr[i] = s1[i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}
char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char            *ptr;
    unsigned int    i;

    i = 0;
    if (!s)
        return (NULL);
    if (start > ft_strlen(s) - 1)
        return (ft_strdup(""));
    if (len > ft_strlen(s) - start - 1)
        len = ft_strlen(s) - start;
    ptr = (char *)malloc((len + 1) * sizeof(char));
    if (!ptr)
        return (NULL);
    while (i < len && start + i < ft_strlen(s))
    {
        ptr[i] = s[start + i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}
