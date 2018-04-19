/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:28:33 by cmasetti          #+#    #+#             */
/*   Updated: 2018/02/18 12:30:31 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		n--;
		s1++;
		s2++;
	}
	return ((n == 0) ? 0 : *(unsigned char *)s1 - *(unsigned char *)s2);
}
