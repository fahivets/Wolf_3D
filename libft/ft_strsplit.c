/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:01:23 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/03/29 20:55:21 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	char	**token;
	size_t	id;
	size_t	len;
	char	*delim;

	delim = (char *)ft_memalloc(2);
	if (s == NULL || c == 0 || delim == NULL)
		return (NULL);
	delim[0] = (char)c;
	if (!(token = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	id = 0;
	while (*s)
	{
		s = s + ft_strspn(s, delim);
		if (!*s)
			break ;
		len = ft_strcspn(s, delim);
		if (!(token[id++] = ft_strsub(s, 0, len)))
			return (NULL);
		s = s + len;
	}
	token[id] = 0;
	free(delim);
	return (token);
}
