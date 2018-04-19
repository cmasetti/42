/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:11:28 by cmasetti          #+#    #+#             */
/*   Updated: 2018/04/12 12:17:00 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

void	lstjoin(t_list **alst1, t_list **alst2)
{
	if (!alst1 || !alst2)
		return ;
	if ((*alst1)->next)
		lstjoin(&((*alst1)->next), alst2);
	else
		(*alst1)->next = *alst2;
}

void	lstmerge(t_list **alst1, t_list **alst2)
{
	char	*tmp;
//	ft_putstr("\n s1 avant strjoin = ");//E
//	ft_putstr((*alst1)->content);//E
	if (!alst1 || !alst2)
		return ;
	if ((*alst1)->next)
		lstmerge(&((*alst1)->next), alst2);
	else
	{
		//if ((*alst2)->next)
			(*alst1)->next = (*alst2)->next;
		tmp = ft_strjoin((*alst1)->content, (*alst2)->content);
		ft_strdel(&((*alst1)->content));
		ft_strdel(&((*alst2)->content));
		(*alst1)->content = tmp;
	}
}

char	**strsplit_gnl(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	k = 1;
	while (s[i])
	{
		if (s[i] == '\n' && s[i + 1])
			k++;
		i++;
	}
	if (!(tab = (char**)malloc(sizeof(char*) * (k + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		k = 0;
		while (s[i + k] != '\n' && s[i + k])
			k++;
		tab[j] = ft_memalloc(sizeof(char) * (k + 1));
		k = 0;
		while (s[i] != '\n' && s[i])
			tab[j][k++] = s[i++];
		tab[j++][k] = '\0';
		if (s[i] == '\n')
			i++;
	}
	tab[j] = NULL;
	return (tab);//tab good 
}	

int		get_next_line(const int fd, char **line)
{
	int				n;
	char			str[BUFF_SIZE];
	static t_list	**alst;
	int				retu;
	t_list			**tmp;

	n = read(fd, str, BUFF_SIZE);
	if (!line || n < 0)
		return (-1);
	if (n != 0)
	{
		str[n] = '\0';
//		ft_putstr(str);//E
//		ft_putstr(" : str\n");//E
		alst = ft_arrtolst(strsplit_gnl(str));// PB ICI sur dernier troncon construit
		while (n == BUFF_SIZE)
		{
			retu = 0;
			if (str[n - 1] == '\n')
				retu = 1;
			ft_strclr(str);
			n = read(fd, str, BUFF_SIZE);
		str[n] = '\0';//ADDED
//		ft_putstr(str);//E
//		ft_putstr(" : str\n");//E
		tmp = ft_arrtolst(strsplit_gnl(str));//replace tmp
			if (retu == 1 || str[0] == '\n')
				lstjoin(alst, tmp);//replace tmp
			else
				lstmerge(alst, tmp);//replace tmp
		free (tmp);//replace tmp
		}
	}
	if (*alst == NULL)
		return 0;
	*line  = (*alst)->content;
	*alst = (*alst)->next;
	return (1);
}
