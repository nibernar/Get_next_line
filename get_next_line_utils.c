/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:31:14 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/07 16:01:20 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Find the first occurrence of a given character in a string.
 * 
 * @param s Pointer to the string 's' in which to search for the character.
 * @param c The character to be searched for in the string.
 * @return A string to the first occurrence of the character. 
 * If character 'c' is not found in the string, the function returns NULL.
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)(c))
		i++;
	if (s[i] == (char)(c))
		return (((char *)s) + i);
	return (0);
}

/**
 * @brief Find length of string.
 * 
 * @param s Pointer to string 's'.
 * @return Total length of string 's'.
 */
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * @brief Copy a string and create a new string.
 * 
 * @param s Pointer to the string 's' to duplicate.
 * @return A new duplicate string or returns NULL if the allocation fails.
 */
char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * @brief Allocates dynamic memory for an array of elements of specified size,
 * and initializes all bytes of this memory to zero.
 * 
 * @param count The number of elements to be allocated in the array.
 * @param n Size of each item in bytes.
 * @return An array of elements initialized to zero.
 */
void	*ft_calloc(size_t count, size_t n)
{
	void	*memstr;
	size_t	i;
	size_t	j;

	i = 0;
	if (n && count > SIZE_MAX / n)
		return (NULL);
	memstr = (void *)malloc(count * n);
	if (!memstr)
		return (0);
	j = count * n;
	while (i < n)
	{
		((char *)memstr)[i] = 0;
		i++;
	}
	return (memstr);
}

/**
 * @brief Allocates and returns a 'new' string ending with ’\0’,
 * result of the concatenation of 's1' and 's2'. If the allocation fails the function returns NULL.
 * 
 * @param s1 The string 's1'.
 * @param s2 The string 's2'.
 * @return A 'new' string ending with ’\0’ or NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

char	*end_of_file(char *buffer, char *tmp, int flag)
{
	char	*temp;

	tmp[flag] = '\0';
	temp = ft_strjoin(buffer, tmp);
	free(buffer);
	buffer = NULL;
	free(tmp);
	tmp = NULL;
	return (temp);
}
