/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:53:30 by cmasetti          #+#    #+#             */
/*   Updated: 2018/04/19 15:02:56 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const*s1, char const *s2)
{
	char	*d;
	size_t	len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s2len = ft_strlen(s2);
	len = ft_strlen(s1) + ft_strlen(s2);
	d = ft_strnew(len);
	if (d == NULL)
		return (NULL);
	ft_strncpy(d, s1, ft_strlen(s1));
	ft_strncat(d, s2, s2len);
	return (d);
}
