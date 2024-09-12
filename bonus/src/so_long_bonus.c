/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:05:59 by moelkama          #+#    #+#             */
/*   Updated: 2023/02/23 19:24:27 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_initialise(t_list *v)
{
	v->move = 0;
	ft_findposition(v->map, &v->i, &v->j, 'P');
	v->w_pt = "textures_bonus/wall.xpm";
	v->pl_pt = "textures_bonus/playerleft.xpm";
	v->pr_pt = "textures_bonus/player.xpm";
	v->pd_pt = "textures_bonus/playerdown.xpm";
	v->pu_pt = "textures_bonus/playerup.xpm";
	v->f_pt = "textures_bonus/floor.xpm";
	v->c_pt = "textures_bonus/collectible.xpm";
	v->ec_pt = "textures_bonus/exitclose.xpm";
	v->eo_pt = "textures_bonus/exitopen.xpm";
	v->ec_img = mlx_xpm_file_to_image(v->mlx, v->ec_pt, &v->w, &v->h);
	v->eo_img = mlx_xpm_file_to_image(v->mlx, v->eo_pt, &v->w, &v->h);
	v->w_img = mlx_xpm_file_to_image(v->mlx, v->w_pt, &v->w, &v->h);
	v->pl_img = mlx_xpm_file_to_image(v->mlx, v->pl_pt, &v->w, &v->h);
	v->pr_img = mlx_xpm_file_to_image(v->mlx, v->pr_pt, &v->w, &v->h);
	v->pd_img = mlx_xpm_file_to_image(v->mlx, v->pd_pt, &v->w, &v->h);
	v->pu_img = mlx_xpm_file_to_image(v->mlx, v->pu_pt, &v->w, &v->h);
	v->f_img = mlx_xpm_file_to_image(v->mlx, v->f_pt, &v->w, &v->h);
	v->c_img = mlx_xpm_file_to_image(v->mlx, v->c_pt, &v->w, &v->h);
	v->p_img = v->pd_img;
	ft_initialise_enemy(v);
}

void	ft_putwindow(t_list v)
{
	int	i;
	int	j;

	i = 0;
	while (v.map[i])
	{
		j = 0;
		while (v.map[i][j])
		{
			ft_put(v, i, j);
			j++;
		}
		i++;
	}
}

void	ft_change(t_list *v, int x, int y)
{
	char	*nbr;
	int		x_e;
	int		y_e;

	v->map[v->i][v->j] = '0';
	v->map[v->i + x][v->j + y] = 'P';
	if (!ft_countchar(v->map, 'C') && ft_countchar(v->map, 'E'))
	{
		ft_findposition(v->map, &x_e, &y_e, 'E');
		v->map[x_e][y_e] = 'e';
	}
	if (y == -1)
		v->p_img = v->pl_img;
	else if (y == 1)
		v->p_img = v->pr_img;
	else if (x == -1)
		v->p_img = v->pu_img;
	else if (x == 1)
		v->p_img = v->pd_img;
	v->move++;
	v->j += y;
	v->i += x;
}

int	ft_move(int key, t_list *v)
{
	if (key == 53 || key == 17)
		exit(1);
	if ((key == 0 || key == 123) && is_exist("FRe", v->map[v->i][v->j - 1]))
		exit(1);
	if ((key == 2 || key == 124) && is_exist("FRe", v->map[v->i][v->j + 1]))
		exit(1);
	if ((key == 1 || key == 125) && is_exist("FRe", v->map[v->i + 1][v->j]))
		exit(1);
	if ((key == 13 || key == 126) && is_exist("FRe", v->map[v->i - 1][v->j]))
		exit(1);
	if ((key == 0 || key == 123) && is_exist("C0", v->map[v->i][v->j - 1]))
		ft_change(v, 0, -1);
	if ((key == 2 || key == 124) && is_exist("C0", v->map[v->i][v->j + 1]))
		ft_change(v, 0, 1);
	if ((key == 1 || key == 125) && is_exist("C0", v->map[v->i + 1][v->j]))
		ft_change(v, 1, 0);
	if ((key == 13 || key == 126) && is_exist("C0", v->map[v->i - 1][v->j]))
		ft_change(v, -1, 0);
	return (0);
}

int	main(int c, char **v)
{
	t_list	var;
	char	*file;
	int		w;
	int		h;

	file = readfile(v[1]);
	if (c == 2 && ft_check_newline(file) && check_map(file, v[1], ".ber"))
	{
		var.mlx = mlx_init();
		var.map = ft_split(file, '\n');
		ft_initialise(&var);
		if (ft_check_img(var))
		{
			w = ft_strlen(var.map[0]) * var.w;
			h = ft_count_strs(file, '\n') * var.h;
			var.win = mlx_new_window(var.mlx, w, h, "so_long");
			mlx_loop_hook(var.mlx, move_enemy, &var);
			mlx_hook(var.win, 2, 0, ft_move, &var);
			mlx_hook(var.win, 17, 0, ft_close, &var);
			mlx_loop(var.mlx);
		}
	}
}
