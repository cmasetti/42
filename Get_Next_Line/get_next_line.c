/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:11:28 by cmasetti          #+#    #+#             */
/*   Updated: 2018/08/09 12:03:43 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

int		charpos(char *str, char c)
{
	int			i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			return (i);
		i++;
		str++;
	}
	return (-1);
}

//function to copy a string after the z chracters and free the tmp variable

char	*strzcpy(int z, char *str)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (len <= z)
	{
		tmp = NULL;
		return (tmp);
	}
	tmp = ft_strnew(len - z);
	while (z + i <= len)
	{
		tmp[i] = str[z + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

//join s1 and beginning (n chars) of s2 + free everything
char	*strnjoin(char *s1, int n, char *s2)
{
	char	*newstr;
	int		len;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	if (!s1)
	{
		if ((newstr = ft_strnew(n)) == NULL)
			return (NULL);
		ft_strncpy(newstr, s2, n);
	}
	else
	{
		len = ft_strlen(s1) + n;
		if ((newstr = ft_strnew(len)) == NULL)
			return (NULL);
		ft_strncpy(newstr, s1, ft_strlen(s1));
		ft_strncat(newstr, s2, n);
	}
	return (newstr);
}

int		get_next_line(const int fd, char **line)
{
	static char	*strpast;
	char		str[BUFF_SIZE + 1];
	int			n;
	char		*tmp;

	if (strpast != 0 && charpos(strpast, '\n') >= 0)//plusieurs lignes stockees
	{
		if (*line)
		{
			ft_strclr(*line);
			free(*line);//DEL?
		}
		*line = strnjoin(NULL, charpos(strpast, '\n'), strpast);
		//strpast = strzcpy(charpos(strpast, '\n') + 1, strpast);//without tmp
		tmp = strzcpy(charpos(strpast, '\n') + 1, strpast);
		if (strpast)//mettre cela avant allocations strpast
		{
			ft_strclr(strpast);
			free(strpast);
		}
		strpast = tmp;
		return (1);
	}
	n = read(fd, str, BUFF_SIZE);//si strpast nul ou reste dune ligne seulement
	if (strpast == 0 && n == 0)//fin de lecture (strpast nul et plus rien a lire)
	{
		return (0);
	}
	if (n < 0)
		return (-1);
	if (n == 0)// plus rien a lire mais reste encore stocke dans strpast
	{
		if (*line)
		{
			ft_strclr(*line);
			free(*line);//DEL?
		}
		*line = ft_strtrim(strpast);
		ft_strclr(strpast);//cest la ou faut free aussi
		strpast = NULL;//free(strpast) et firee(str) ?
		return (1);
	}
	str[n] = '\0';
	if (charpos(str, '\n') >= 0)// plusieures lignes lues
	{
		if (*line)
		{
			ft_strclr(*line);
			free(*line);//DEL?
		}
		*line = strnjoin(strpast, charpos(str, '\n'), str);//ok
		ft_strclr(strpast);//
		if (strpast)
		{
			ft_strclr(strpast);
			free(strpast);//GOOD
		}
		strpast = strzcpy(charpos(str, '\n') + 1, str);
	}
	else
	{
		//strpast = strnjoin(strpast, ft_strlen(str), str);//without tmp
		tmp = strnjoin(strpast, ft_strlen(str), str);//without tmp
		if (strpast)//mettre cela avant allocations strpast
		{
			ft_strclr(strpast);
			free(strpast);
		}
		strpast = tmp;
		get_next_line(fd, line);
	}
	ft_strclr(str);//memset str, besoin?
	return (1);
}
