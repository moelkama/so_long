/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:20:48 by moelkama          #+#    #+#             */
/*   Updated: 2023/02/16 16:46:01 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_nbrlen(long nb)
{
	int		k;

	k = 1;
	while (nb / 10 != 0)
	{
		k *= 10;
		nb /= 10;
	}
	return (k);
}

void	ft_putnbr(int n)
{
	long	nb;
	char	num;
	int		k;

	nb = n;
	k = ft_nbrlen(nb);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	while (k >= 1)
	{
		num = nb / k + 48;
		write(1, &num, 1);
		nb %= k;
		k /= 10;
	}
}
