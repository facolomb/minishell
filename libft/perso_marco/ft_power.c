/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:50:59 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/01/15 12:51:01 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "perso_marco.h"

int	ft_power(int nb, int power)
{
	while (power-- > 1)
		nb *= nb;
	return (nb);
}
