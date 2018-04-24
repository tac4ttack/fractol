/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 23:34:30 by fmessina          #+#    #+#             */
/*   Updated: 2016/11/23 17:25:17 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	res[len] = '\0';
	while (len--)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	return (res);
}
