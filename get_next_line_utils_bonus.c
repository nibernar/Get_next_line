/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:31:32 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/07 21:55:23 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
 * @brief Copy a string and create a new string.
 * 
 * @param s Pointer to the string 's' to duplicate.
 * @return A new duplicate string or returns NULL if the allocation fails.
 */
char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
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
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = ft_calloc(sizeof(char *), (i + j + 1));
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