/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:53:04 by cmasetti          #+#    #+#             */
/*   Updated: 2018/04/12 15:02:38 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h> //to take off

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	printf("%s", s);//test
	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
