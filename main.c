/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:03:03 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/28 19:02:37 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		real;
	int		img;

	real = printf(av[1], atoi(av[2]), atoi(av[3]));
	img = ft_printf(av[1], atoi(av[2]), atoi(av[3]));

	ft_printf ("PRINTF : %d, FT_PRINTF : %d\n", real, img);
	return (0);
}
