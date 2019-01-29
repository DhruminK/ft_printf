/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:03:03 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/29 18:55:02 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		real;
	int		img;
	signed char		s;
	long long		l;
	int				i;

	i = 128;
	l = (signed char)i;
	real = printf(av[1], 0);
	img = ft_printf(av[1], 0);

	ft_printf ("PRINTF : %d, FT_PRINTF : %d\n", real, img);
	return (0);
}
