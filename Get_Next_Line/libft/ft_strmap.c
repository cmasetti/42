/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:18:45 by cmasetti          #+#    #+#             */
/*   Updated: 2018/02/18 12:35:59 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*d;

	if (!s || !f)
		return (NULL);
	d = ft_strnew(ft_strlen(s));
	if (d == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = f(s[i]);
		i++;
	}
	return (d);
}
