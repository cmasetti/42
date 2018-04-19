/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:53:04 by cmasetti          #+#    #+#             */
/*   Updated: 2018/04/19 14:52:24 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	write(1, "a", 1);//test
	i = 0;
	while (s && s[i])
		i++;
	write(1, "b", 1);//test
	return (i);
}
