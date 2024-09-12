/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:51:11 by moelkama          #+#    #+#             */
/*   Updated: 2023/02/23 17:25:53 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H

# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 100

# endif

# include <stdlib.h>

# include <unistd.h>

# include <fcntl.h>

# include <mlx.h>

typedef struct s_list
{
	void	*mlx;
	void	*win;
	char	**map;
	char	*pl_pt;
	char	*pr_pt;
	char	*pu_pt;
	char	*pd_pt;
	char	*w_pt;
	char	*ec_pt;
	char	*eo_pt;
	char	*c_pt;
	char	*f_pt;
	char	*enemyl_pt;
	char	*enemyr_pt;
	void	*p_img;
	void	*pl_img;
	void	*pr_img;
	void	*pu_img;
	void	*pd_img;
	void	*w_img;
	void	*ec_img;
	void	*eo_img;
	void	*c_img;
	void	*f_img;
	void	*e_img;
	void	*enemyl_img;
	void	*enemyr_img;
	void	*r_img;
	int		move;
	int		w;
	int		h;
	int		i;
	int		j;
	int		x;
	int		y;
}			t_list;

char	**ft_split(char *str, char c);
char	*readfile(char *str);
char	*ft_link(char *s1, char *s2);
char	*ft_itoa(int n);
int		ft_puterror(int key, int p, int c, int e);
int		check_map(char *file, char *str, char *ptr);
int		ft_check_newline(char *file);
int		ft_check_img(t_list var);
int		ft_count_strs(char *s, char c);
int		ft_countchar(char **strs, char c);
int		is_exist(char *str, char c);
int		ft_free(char **ptr);
int		ft_strlen(char *str);
int		ft_close(void);
int		move_enemy(t_list *v);
void	ft_put(t_list v, int i, int j);
void	ft_findposition(char **strs, int *x, int *y, char c);
void	ft_bezero(char *str);
void	change_enemy(t_list *v, int *move, int y);
void	ft_initialise_enemy(t_list *v);
void	animation(t_list *v);
void	ft_putwindow(t_list v);

#endif
