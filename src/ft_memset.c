/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 09:09:18 by sait-mou          #+#    #+#             */
/*   Updated: 2026/01/25 10:46:43 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	value;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	value = (unsigned char)c;
	while (n-- > 0)
		*ptr++ = value;
	return (s);
}
