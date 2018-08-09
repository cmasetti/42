/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student@42 <@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 22:10:06 by student@42        #+#    #+#             */
/*   Updated: 2018/08/09 10:55:14 by cmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include "libft/includes/libft.h"

int	get_next_line(int fd, char **line);

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc < 2)
	{
		printf("Usage %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		close(fd);
		return (-1);
	}
//	get_next_line(fd, &line);
	while ((get_next_line(fd, &line) != 0))
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
	}
	//si le fichier test n a pas de \n et que ca affiche une erreur c'est normal
	free(line);// vous inquietez pas
	close(fd);
	return (0);
}
