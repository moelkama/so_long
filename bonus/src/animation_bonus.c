/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:20:46 by moelkama          #+#    #+#             */
/*   Updated: 2023/02/23 17:36:49 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_initialise_enemy(t_list *v)
{
	ft_findposition(v->map, &v->x, &v->y, 'F');
	v->enemyr_pt = "textures_bonus/enemyright.xpm";
	v->enemyl_pt = "textures_bonus/enemyleft.xpm";
	v->enemyl_img = mlx_xpm_file_to_image(v->mlx, v->enemyl_pt, &v->w, &v->h);
	v->enemyr_img = mlx_xpm_file_to_image(v->mlx, v->enemyr_pt, &v->w, &v->h);
	v->e_img = v->enemyr_img;
}

void	change_enemy(t_list *v, int *move, int y)
{
	v->map[v->x][v->y] = '0';
	v->map[v->x][v->y + y] = 'F';
	v->y += y;
	*move = 0;
}

int	move_enemy(t_list *v)
{
	static int	k;
	static int	move;

	animation(v);
	if (k == 0 && v->map[v->x][v->y - 1] == 'P')
		exit(1);
	else if (k == 1 && v->map[v->x][v->y + 1] == 'P')
		exit(1);
	if (k == 0 && v->map[v->x][v->y + 1] == '0' && move == 4)
		change_enemy(v, &move, 1);
	else if (k == 1 && v->map[v->x][v->y - 1] == '0' && move == 4)
		change_enemy(v, &move, -1);
	else if (k == 0 && v->map[v->x][v->y + 1] != '0')
	{
		k = 1;
		v->e_img = v->enemyl_img;
	}
	else if (k == 1 && v->map[v->x][v->y - 1] != '0')
	{
		v->e_img = v->enemyr_img;
		k = 0;
	}
	ft_putwindow(*v);
	move++;
	return (0);
}

void	animation(t_list *v)
{
	static int	i;
	char		*ptr;
	int			m;
	int			n;

	ptr = ft_link("textures_bonus/00.xpm", NULL);
	ptr[15] = i / 10 + 48;
	ptr[16] = i % 10 + 48;
	v->r_img = mlx_xpm_file_to_image(v->mlx, ptr, &m, &n);
	free(ptr);
	if (i == 18)
		i = 0;
	i++;
}
