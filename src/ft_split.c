/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:02:07 by sait-mou          #+#    #+#             */
/*   Updated: 2026/01/25 10:46:43 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	*ft_free(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static	int	ft_word_count(const char *s, char c)
{
	int	in_word;
	int	count;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static	int	ft_splitter(char const	*s, char c, char **arr, int split_count)
{
	int	arr_i;
	int	word_len;

	arr_i = 0;
	while (arr_i < split_count)
	{
		while (*s == c)
			s++;
		word_len = 0;
		while (s[word_len] && s[word_len] != c)
			word_len++;
		arr[arr_i] = (char *)malloc((word_len + 1) * sizeof(char));
		if (!arr[arr_i])
			return (0);
		ft_strlcpy(arr[arr_i], (char *)s, word_len + 1);
		s += word_len;
		arr_i++;
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		count;

	if (!s)
		return (NULL);
	count = ft_word_count(s, c);
	arr = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	if (!ft_splitter(s, c, arr, count))
		return (ft_free(arr, count));
	arr[count] = NULL;
	return (arr);
}
