/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrtolst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 10:57:57 by cmasetti          #+#    #+#             */
/*   Updated: 2018/07/22 12:31:05 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	**ft_arrtolst(char **tab)
{
	int		i;
	t_list	**alst;
	t_list	*onelst;
	t_list	*tmplst;

	i = ft_arrlen(tab) - 1;
	if (i >= 0)
	{
		onelst = ft_lstnew(tab[i], (int)ft_strlen(tab[i]));
		alst = &onelst;
	}
	i--;
	while (i >= 0)
	{
		tmplst = ft_lstnew(tab[i], (int)ft_strlen(tab[i]));
		ft_lstadd(alst, tmplst);
		free(tmplst);
		free(tab[i]);
		i--;
	}
	free(tab);
	return (alst);
}
