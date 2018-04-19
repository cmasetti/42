/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrtolst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 10:57:57 by cmasetti          #+#    #+#             */
/*   Updated: 2018/04/12 14:16:33 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	**ft_arrtolst(char **tab)
{
	int		i;
	t_list	**alst;
	t_list	*tmplst;

	i = ft_arrlen(tab);
	i--;
	alst = NULL;
	while (tab[i])
	{
//		ft_putstr("\ntab[i] : ");//test
//		ft_putstr(tab[i]);//test
		tmplst = ft_lstnew(tab[i], (int)ft_strlen(tab[i]));
		ft_lstadd(alst, tmplst);
		free(tmplst);
		free(tab[i]);
		i--;
	}
	free(tab);
	return (alst);
}
