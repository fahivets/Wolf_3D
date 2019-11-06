/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:29:46 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/01/07 20:33:39 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		i;

	i = 0;
	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if ((strjoin = (char *)malloc(sizeof(*strjoin) *
					((ft_strlen(s1) + ft_strlen(s2)) + 1))) == NULL)
		return (NULL);
	while (*s1)
		strjoin[i++] = *s1++;
	while (*s2)
		strjoin[i++] = *s2++;
	strjoin[i] = '\0';
	return (strjoin);
}
