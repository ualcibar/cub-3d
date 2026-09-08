/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_libft_funs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:08:50 by ullorent          #+#    #+#             */
/*   Updated: 2023/04/13 15:57:29 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strtrim_modified(char const *s1)
{
	int		len;
	int		index;
	int		endian;
	char	*str;

	len = 0;
	index = 0;
	endian = 0;
	if (!s1)
		return (NULL);
	while ((s1[index] == ' ') || (s1[index] >= 9 && s1[index] <= 13))
		index++;
	len = ft_strlen(s1) - 1;
	while (len > 0 && ((s1[len] == ' ') || (s1[len] >= 9 && s1[len] <= 13)))
		len--;
	str = ft_substr(s1, index, len - index + 1);
	return (str);
}

char	*ft_strjoin_c3(char *s1, char *s2, int width, int width2)
{
	size_t	c;
	size_t	i;
	char	*mem;

	c = 0;
	i = 0;
	if (!s1)
		return (0);
	if (!s2)
		return ((char *)s1);
	mem = malloc(ft_strlen(s1) + ft_strlen(s2) + width + 1);
	if (!mem)
		return (NULL);
	while (s1[c] != '\0')
		*mem++ = s1[c++];
	while (s2[i] != '\0')
		*mem++ = s2[i++];
	while (width-- > 0)
		*mem++ = 'X';
	*mem = '\0';
	free(s2);
	free(s1);
	return (mem - c - i - width2);
}
