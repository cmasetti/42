/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:11:28 by cmasetti          #+#    #+#             */
/*   Updated: 2018/07/22 13:44:43 by cmasetti         ###   ########.fr       */
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

int		get_next_line(const int fd, char **line)
{
	static char	*strpast;
	char		str[BUFF_SIZE + 1];
	int			n;
	char		*tmp;

	if (strpast != 0 && charpos(strpast, '\n') >= 0)
	{
		*line = ft_strnew(charpos(strpast, '\n'));
		ft_strncpy(*line, strpast, charpos(strpast, '\n'));
		strpast = strpast(reste);
		strpast = tmp;
		return (1);
	}
	n = read(fd, str, BUFF_SIZE); //si \n pas present dans strpast ou que strpast est nul
	if (strpast == 0 && n == 0)
		return (0);
	if (n < 0)
		return (-1);
	if (n == 0)
	{
		*line = ft_strtrim(strpast);
		ft_strdel(strpast);
		return (1);
	}
	str[n] = '\0';
	if (charpos(str, '\n') >= 0)
	{
		*line = join(strpast, str(debut));
		strpast = str(reste);
		return (1);
	}
	else
	{
		strpast = ft_strjoin(strpast, str); //faire join special qui free strpast ancien et str
		get_next_line(fd, line);
	}
}
