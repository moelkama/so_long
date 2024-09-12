/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:58:21 by moelkama          #+#    #+#             */
/*   Updated: 2023/02/22 14:09:12 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

void	ft_bezero(char *str)
{
	int	i;

	i = 0;
	while (str && i < BUFFER_SIZE + 1)
		str[i++] = '\0';
}

char	*ft_link(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len * sizeof(char ) + sizeof(char ));
	if (str)
	{
		i = 0;
		j = 0;
		while (s1 && s1[j])
			str[i++] = s1[j++];
		j = 0;
		while (s2 && i < len)
			str[i++] = s2[j++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

char	*readfile(char *file)
{
	char	*str;
	char	*reg;
	char	*swp;
	int		fd;
	int		x;

	str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char ));
	reg = NULL;
	fd = open(file, O_RDONLY);
	if (str)
	{
		ft_bezero(str);
		x = read(fd, str, BUFFER_SIZE);
		while (x > 0)
		{
			swp = reg;
			reg = ft_link(reg, str);
			ft_bezero(str);
			x = read(fd, str, BUFFER_SIZE);
			free(swp);
		}
		free(str);
	}
	return (reg);
}
