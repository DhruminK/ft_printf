/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:32:18 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/22 17:46:04 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/ft_printf.h"

int		main(int ac, char **av)
{
	int real;
	int img;
	char	*str = "MY NAME IS DHRUMIN KHATRI";
	char	ch = 'a';

	img = ft_printf("%0#6o\n", 12);
	real = printf("%0#6o\n", 12);
	ft_printf("PRINTF : %d\tFT_PRINTF : %d", real, img);
	return (0);
}
