/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 11:16:33 by cmasetti          #+#    #+#             */
/*   Updated: 2018/02/18 12:26:24 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_countdec(int n)
{
	long	l;
	int		count;

	l = n;
	count = 0;
	if (l < 0)
	{
		count++;
		l = -l;
	}
	while (l > 9)
	{
		count++;
		l /= 10;
	}
	count++;
	return (count);
}
