/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:01:38 by ullorent          #+#    #+#             */
/*   Updated: 2023/04/19 19:33:54 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_wrdlen(char *s, char c)
{
	int	wrd;
	int	boo;
	int	i;

	wrd = 0;
	boo = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && boo == 0)
		{
			wrd++;
			boo = 1;
		}
		else if (s[i] == c)
			boo = 0;
		i++;
	}
	return (wrd);
}

char	*ft_wrdcomplete(char **s, char c)
{
	char	*nstr;
	char	*end;
	int		len;

	len = 0;
	while (**s == ' ')
		(*s)++;
	end = ft_strchr(*s, c);
	if (end == NULL)
		len = ft_strlen(*s);
	else
		len = end - *s;
	nstr = ft_substr(*s, 0, len);
	*s += len;
	while (**s == ' ')
		(*s)++;
	return (nstr);
}

void	ft_wrdfree(char ***temp)
{
	int	i;

	i = 0;
	while ((*temp)[i] != NULL)
	{
		free((*temp)[i]);
		i++;
	}
	free(*temp);
}

char	**ft_split(char const *s, char c)
{
	char	**temp;
	int		count;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_wrdlen((char *)s, c);
	temp = (char **)malloc(sizeof(char *) * (count + 1));
	if (!temp)
		return (NULL);
	temp[count] = NULL;
	while (s && count--)
	{
		while (*s == c && *s != '\0')
			s++;
		temp[i] = ft_wrdcomplete((char **)&s, c);
		if (!temp[i])
		{
			ft_wrdfree(&temp);
			return (0);
		}
		i++;
	}
	return (temp);
}
