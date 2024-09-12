/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:04:10 by moelkama          #+#    #+#             */
/*   Updated: 2023/02/23 12:39:56 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_puterror(int key, int p, int c, int e)
{
	if (key == 1)
		write(2, "Error\nfile path is incorrect\n", 29);
	else if (key == 2)
		write(2, "Error\nIncorrect character in map\n", 34);
	else if (key == 3 && p == 0)
		write(2, "Error\nplayer not exist\n", 23);
	else if (key == 3 && p > 1)
		write(2, "Error\nonly one player\n", 22);
	else if (key == 3 && c == 0)
		write(2, "Error\none collectible at least\n", 28);
	else if (key == 3 && e == 0)
		write(2, "Error\nexit not exist\n", 21);
	else if (key == 3 && e > 1)
		write(2, "Error\nonly one exit\n", 19);
	else if (key == 4)
		write(2, "Error\nmap is not rectangular\n", 29);
	else if (key == 5)
		write(2, "Error\nwalls is not protected\n", 29);
	else if (key == 6)
		write(2, "Error\nno way from player to exit\n", 32);
	else if (key == 7)
		write(2, "Error\nno way from player to collectible\n", 41);
	return (0);
}

int	ft_close(void)
{
	exit(0);
	return (0);
}
