/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:32:18 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/21 17:32:03 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/ft_printf.h"

int		main(void)
{
	int real;
	int img;
	char	*str = "MY NAME IS DHRUMIN KHATRI";
	char	ch = 'a';

	real = printf ("%s %x %Lf %c\n", str, -50, -50.24L, ch);
	img = ft_printf("%s %x %llf %c\n", str, -50, -50.24L, ch);
	ft_printf("PRINTF : %d\tFT_PRINTF : %d", real, img);
	return (0);
}
