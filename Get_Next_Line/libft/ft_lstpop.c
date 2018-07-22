/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 11:31:10 by cmasetti          #+#    #+#             */
/*   Updated: 2018/07/22 12:30:33 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstpop(t_list **alst)
{
	t_list	*lst;

	if (!alst || !(*alst))
		return (NULL);
	lst = *alst;
	if (lst->next)
		*alst = lst->next;
	else
		*alst = NULL;
	lst->next = NULL;
	return (lst);
}
