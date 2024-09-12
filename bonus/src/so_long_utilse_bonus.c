/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utilse_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:58:32 by moelkama          #+#    #+#             */
/*   Updated: 2023/02/23 17:26:02 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_newline(char *file)
{
	int	i;

	i = 0;
	if (!file)
		return (write(2, "Error\nNo such file or map is emty\n", 34), 0);
	while (file[i])
	{
		if (file[i] == '\n' && file[i + 1] == '\n')
			return (ft_puterror(4, 0, 0, 0), 0);
		i++;
	}
	if (file[0] == '\n' || file[i - 1] == '\n')
		return (ft_puterror(4, 0, 0, 0), 0);
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
	if (!var.enemyr_img || !var.enemyl_img)
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
	char	*nbr;

	mlx_put_image_to_window(v.mlx, v.win, v.f_img, j * v.w, i * v.h);
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
	else if (v.map[i][j] == 'C')
		mlx_put_image_to_window(v.mlx, v.win, v.c_img, j * v.w, i * v.h);
	else if (v.map[i][j] == 'F')
		mlx_put_image_to_window(v.mlx, v.win, v.e_img, j * v.w, i * v.h);
	else if (v.map[i][j] == 'R')
		mlx_put_image_to_window(v.mlx, v.win, v.r_img, j * v.w, i * v.h);
	nbr = ft_itoa(v.move);
	mlx_string_put(v.mlx, v.win, 0, 0, 0, nbr);
	free(nbr);
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
