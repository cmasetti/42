/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 11:11:33 by cmasetti          #+#    #+#             */
/*   Updated: 2018/02/18 12:28:12 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa(int n)
{
	int		dec;
	long	l;
	char	*str;

	dec = ft_countdec(n);
	l = n;
	str = (char *)malloc(sizeof(*str) * (dec + 1));
	if (str == 0)
		return (NULL);
	str[dec--] = '\0';
	if (l == 0)
		return (ft_strdup("0"));
	if (l < 0)
	{
		str[0] = '-';
		l = -l;
	}
	while (l > 0)
	{
		str[dec] = l % 10 + 48;
		l /= 10;
		dec--;
	}
	return (str);
}
