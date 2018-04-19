/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswspc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:14:43 by cmasetti          #+#    #+#             */
/*   Updated: 2018/02/18 12:27:50 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_iswspc(int c)
{
	return (((c >= 9 && c <= 13) || c == ' ') ? 1 : 0);
}