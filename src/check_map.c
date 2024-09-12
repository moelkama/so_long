/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:54:45 by moelkama          #+#    #+#             */
/*   Updated: 2023/02/18 12:02:12 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_countchar(char **strs, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (strs && strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	way_is_vid(char **map, int i, int j, char c)
{
	int	k;

	k = 0;
	if (map[i][j + 1] == c || (j > 0 && map[i][j - 1] == c))
		return (1);
	if ((map[i + 1] && map[i + 1][j] == c) || (i > 0 && map[i - 1][j] == c))
		return (1);
	map[i][j] = ' ';
	if (is_exist("C0", map[i][j + 1]))
		k = way_is_vid(map, i, j + 1, c);
	if (k == 0 && j > 0 && is_exist("C0", map[i][j - 1]))
		k = way_is_vid(map, i, j - 1, c);
	if (k == 0 && map[i + 1] && is_exist("C0", map[i + 1][j]))
		k = way_is_vid(map, i + 1, j, c);
	if (k == 0 && i > 0 && is_exist("C0", map[i - 1][j]))
		k = way_is_vid(map, i - 1, j, c);
	return (k);
}

int	wall_is_protected(char **map, char *file, int i, int j)
{
	char	**map1;

	if (i > 0 && ft_strlen(map[i]) != ft_strlen(map[i - 1]))
		return (ft_puterror(4, 0, 0, 0), 0);
	if ((i == 0 && map[i][j] != '1') || (!map[i + 1] && map[i][j] != '1'))
		return (ft_puterror(5, 0, 0, 0), 0);
	if ((j == 0 && map[i][j] != '1') || (!map[i][j + 1] && map[i][j] != '1'))
		return (ft_puterror(5, 0, 0, 0), 0);
	map1 = ft_split(file, '\n');
	if (map[i][j] == 'P' && !way_is_vid(map1, i, j, 'E'))
		return (ft_puterror(6, 0, 0, 0), ft_free(map1));
	if (map[i][j] == 'C' && !way_is_vid(map1, i, j, 'P'))
		return (ft_puterror(7, 0, 0, 0), ft_free(map1));
	return (ft_free(map1) + 1);
}

int	check(char **map, char *file)
{
	int	i;
	int	j;
	int	exit;
	int	player;
	int	collectible;

	i = 0;
	collectible = ft_countchar(map, 'C');
	player = ft_countchar(map, 'P');
	exit = ft_countchar(map, 'E');
	if (collectible == 0 || exit != 1 || player != 1)
		return (ft_puterror(3, player, collectible, exit), ft_free(map));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!wall_is_protected(map, file, i, j))
				return (ft_free(map));
			j++;
		}
		i++;
	}
	return (ft_free(map) + 1);
}

int	check_map(char *file, char *str, char *cmp)
{
	char	**map;
	int		i;
	int		j;

	i = ft_strlen(str) - ft_strlen(cmp);
	while (*cmp)
	{
		if (i <= 0 || str[i++] != *(cmp++) || !map)
			return (ft_puterror(1, 0, 0, 0));
	}
	map = ft_split(file, '\n');
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_exist("01PCE", map[i][j]))
				return (ft_puterror(2, 0, 0, 0), ft_free(map));
			j++;
		}
		i++;
	}
	return (check(map, file));
}
