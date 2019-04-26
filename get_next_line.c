/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nupside <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:18:13 by nupside           #+#    #+#             */
/*   Updated: 2019/04/19 18:24:51 by nupside          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char		*tmp;
	static char	*str[MAX_FD];
	int			ret;
	int			i;

	if (fd < 0 || fd > MAX_FD || !line ||
		!(tmp = (char *)malloc(sizeof(*tmp) * BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		if (!str[fd])
			str[fd] = ft_strsub(tmp, 0, ret);
		else
			str[fd] = ft_strjoin(str[fd], ft_strsub(tmp, 0, ret));
		i = -1;
		while (str[fd][++i])
			if (str[fd][i] == '\n')
			{
				free(tmp);
				if (!(*line = ft_strsub(str[fd], 0, i)))
					return (-1);
				tmp = ft_strdup(str[fd] + i + 1);
				free(str[fd]);
				str[fd] = ft_strdup(tmp);
				free(tmp);
				tmp = 0;
				return (1);
			}
	}
	free(tmp);
	tmp = 0;
	if (ret < 0)
	{
		free(str[fd]);
		str[fd] = 0;
		return (-1);
	}
	if (str[fd])
	{
		i = -1;
		while (str[fd][++i])
			if (str[fd][i] == '\n')
			{
				if (!(*line = ft_strsub(str[fd], 0, i)))
					return (-1);
				tmp = ft_strdup(str[fd] + i + 1);
				free(str[fd]);
				str[fd] = ft_strdup(tmp);
				free(tmp);
				tmp = 0;
				return (1);
			}
		if (*str[fd])
		{
			if (!(*line = ft_strdup(str[fd])))
				return (-1);
			free(str[fd]);
			str[fd] = 0;
			return (1);
		}
	}
	return (0);
}
