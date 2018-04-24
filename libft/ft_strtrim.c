/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:59:36 by fmessina          #+#    #+#             */
/*   Updated: 2017/02/11 13:59:04 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	size_t	b;
	size_t	l;

	if (!s)
		return (NULL);
	b = 0;
	l = ft_strlen(s) - 1;
	while (s[b] && (s[b] == 9 || s[b] == 10 || s[b] == 32))
		b++;
	while (s[l] && l > b && (s[l] == 9 || s[l] == 10 || s[l] == 32))
		l--;
	return (ft_strsub(s, b, l - b + 1));
}
