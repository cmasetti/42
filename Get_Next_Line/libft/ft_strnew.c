/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:13:09 by cmasetti          #+#    #+#             */
/*   Updated: 2018/02/22 16:23:17 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i <= (int)size)
		str[i++] = '\0';
	return (str);
}
