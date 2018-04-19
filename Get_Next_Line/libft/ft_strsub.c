/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:27:15 by cmasetti          #+#    #+#             */
/*   Updated: 2018/02/18 12:38:21 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*d;

	if (!s)
		return (NULL);
	if (len == 0)
		return (ft_strdup(""));
	if (!s[start] || !s[start + len - 1])
		return (NULL);
	d = ft_strnew(len);
	if (d == NULL)
		return (NULL);
	ft_strncpy(d, s + start, len);
	d[len] = '\0';
	return (d);
}
