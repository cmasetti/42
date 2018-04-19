/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:21:57 by cmasetti          #+#    #+#             */
/*   Updated: 2018/04/12 14:11:42 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(char const *content, int content_size)
{
	t_list	*new;

	if (!(new = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size)
	{
		new->content = "\0";
		new->content_size = 0;
	}
	else
	{
		new->content = ft_memalloc(sizeof(char) * (content_size + 1));
		if (!(new->content))
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	ft_putstr("\nft_lstnew : ");//test
	ft_putstr(new->content);//test
	return (new);
}
