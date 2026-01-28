/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:28:19 by sait-mou          #+#    #+#             */
/*   Updated: 2025/11/29 18:06:27 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

size_t ft_strlen(const char *s) {
  size_t i;

  i = 0;
  if (!s)
    return (0);
  while (s[i] != '\0')
    i++;
  return (i);
}

char *ft_strchr(char *s, int c) {
  int i;

  i = 0;
  if (!s)
    return (0);
  if (c == '\0')
    return ((char *)&s[ft_strlen(s)]);
  while (s[i] != '\0') {
    if (s[i] == (char)c)
      return ((char *)&s[i]);
    i++;
  }
  return (0);
}

char *ft_strjoin(char *s1, char *s2) {
  char *res;
  size_t i;
  size_t j;

  if (!s1) {
    s1 = malloc(1);
    if (!s1)
      return (NULL);
    s1[0] = '\0';
  }
  if (!s2)
    return (free(s1), NULL);
  res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
  if (!res)
    return (free(s1), NULL);
  i = -1;
  while (s1[++i])
    res[i] = s1[i];
  j = 0;
  while (s2[j])
    res[i++] = s2[j++];
  res[i] = '\0';
  free(s1);
  return (res);
}
