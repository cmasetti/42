/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:11:28 by cmasetti          #+#    #+#             */
/*   Updated: 2018/08/01 18:12:37 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

//verifier cas !line au debut
//verifier lecture depuis fichier et depuis lentree standard
//ligne vide est lue comme rien
// pas de fuite de memoire, toute memoire allouee est free
// resultat sans \n
// 1 seule variable statique
// gerer plusieurs descripteurs de fichier
//ft_strdel ou free?

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

//function to join a string and beginning (n chars) of another string + free everything
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

	if (strpast != 0 && charpos(strpast, '\n') >= 0)
	{
	//	*line = ft_strnew(charpos(strpast, '\n'));
//		ft_strncpy(*line, strpast, charpos(strpast, '\n'));//ok
		*line = strnjoin(NULL, charpos(strpast, '\n'), strpast);//utiliser strnjoin p cas null
		tmp = strzcpy(charpos(strpast, '\n') + 1, strpast);//errroor tmp semble vide
	ft_putstr(*line);//
	ft_putstr(strpast);//
	ft_putstr("A");//
		ft_strclr(strpast);//clear strpast then reassign
//		free(strpast);//necessaire?
	ft_putstr("A");//
		strpast = tmp;
	ft_putstr("A");//
	ft_putstr(strpast);//
		free(tmp);
		return (1);
	}
	n = read(fd, str, BUFF_SIZE); //si \n pas present dans strpast ou que strpast est nul
	if (strpast == 0 && n == 0)
	{ft_putstr("B");//
		return (0);}
	if (n < 0)
	{ft_putstr("C");//
		return (-1);}
	if (n == 0)
	{
	ft_putstr("D");//
		*line = ft_strtrim(strpast);
		ft_strclr(strpast);//plutot que free pour stopper la boucle infinie ?
		return (1);
	}
	str[n] = '\0';
	if (charpos(str, '\n') >= 0)
	{
	ft_putstr("E");//
		*line = strnjoin(strpast, charpos(str, '\n'), str);//ok
		//free strpast and create new of good size
		tmp = strzcpy(charpos(str, '\n') + 1, str);
		free(strpast);
//		strpast = tmp;//ok
		free(tmp);
		ft_strclr(str);// is this necessary, do i have to do for all cases?
		return (1);
	}
	else
	{
	ft_putstr("F");//
		strpast = ft_strjoin(strpast, str); //faire join special qui free strpast ancien et str
		get_next_line(fd, line);
	}
	ft_putstr("Z");
	return (0);// pour faire disparaitre error may reach end of non void function
}
