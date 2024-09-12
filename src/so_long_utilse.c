/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utilse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:58:32 by moelkama          #+#    #+#             */
/*   Updated: 2023/02/23 17:57:51 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_newline(char *file)
{
	int	i;

	i = 0;
	if (!file)
		return (write(2, "Error\nNo such file or map is empty\n", 36), 0);
	while (file[i])
	{
		if (file[i] == '\n' && file[i + 1] == '\n')
			return (ft_puterror(4, 0, 0, 0));
		i++;
	}
	if (file[0] == '\n' || file[i - 1] == '\n')
		return (ft_puterror(4, 0, 0, 0));
	return (1);
}

int	ft_check_img(t_list var)
{
	if (!var.eo_img || !var.ec_img || !var.p_img)
		return (0);
	if (!var.pr_img || !var.pu_img || !var.pl_img || !var.pd_img)
		return (0);
	if (!var.f_img || !var.c_img || !var.w_img)
		return (0);
	return (1);
}

int	is_exist(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	ft_put(t_list v, int i, int j)
{
	mlx_put_image_to_window(v.mlx, v.win, v.c_img, j * v.w, i * v.h);
	if (v.map[i][j] == '1')
		mlx_put_image_to_window(v.mlx, v.win, v.w_img, j * v.w, i * v.h);
	else if (v.map[i][j] == 'P')
		mlx_put_image_to_window(v.mlx, v.win, v.p_img, j * v.w, i * v.h);
	else if (v.map[i][j] == 'E')
		mlx_put_image_to_window(v.mlx, v.win, v.ec_img, j * v.w, i * v.h);
	else if (v.map[i][j] == 'e')
		mlx_put_image_to_window(v.mlx, v.win, v.eo_img, j * v.w, i * v.h);
	else if (v.map[i][j] == '0')
		mlx_put_image_to_window(v.mlx, v.win, v.f_img, j * v.w, i * v.h);
}

void	ft_findposition(char **strs, int *x, int *y, char c)
{
	int	i;
	int	j;

	i = 0;
	while (strs && strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == c)
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
}
