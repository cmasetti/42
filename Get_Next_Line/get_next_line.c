/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:11:28 by cmasetti          #+#    #+#             */
/*   Updated: 2018/09/12 16:08:13 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

//function to copy a string after the z char

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

//join s1 and first n chars of s2

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

int		gnl_fdread(char **str, char **strpast, int fd, char **line)
{
	int		n;

	n = read(fd, *str, BUFF_SIZE);
	if (n < 0)
		return (-1);
	if (n == 0)
	{
		if (*strpast == 0)
			return (0);
		*line = ft_strtrim(*strpast);
		ft_strclr(*strpast);
		*strpast = NULL;
		return (1);
	}
	(*str)[n] = '\0';
	return (2);
}

void	gnl_fdyes(char **str, char **strpast, int fd, char **line)
{
	char	*tmp;

	tmp = "";
	if (ft_charpos(*str, '\n') >= 0)
	{
		*line = strnjoin(*strpast, ft_charpos(*str, '\n'), *str);
		ft_strclrfree(*strpast);
		*strpast = strzcpy(ft_charpos(*str, '\n') + 1, *str);
	}
	else
	{
		tmp = strnjoin(*strpast, ft_strlen(*str), *str);
		ft_strclrfree(*strpast);
		*strpast = tmp;
		get_next_line(fd, line);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	*strpast;
	char		*str;
	char		*tmp;
	int			ret;

	str = ft_memalloc(BUFF_SIZE + 1);
	if (strpast != 0 && ft_charpos(strpast, '\n') >= 0)
	{
		*line = strnjoin(NULL, ft_charpos(strpast, '\n'), strpast);
		tmp = strzcpy(ft_charpos(strpast, '\n') + 1, strpast);
		ft_strclrfree(strpast);
		strpast = tmp;
		return (1);
	}
	ret = gnl_fdread(&str, &strpast, fd, line);
	if (ret != 2)
		return (ret);
	gnl_fdyes(&str, &strpast, fd, line);
	ft_strclrfree(str);
	return (1);
}
