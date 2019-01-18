/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:32:18 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/18 18:09:57 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/ft_printf.h"

int		main(void)
{
	int real;
	int img;
	char	*str = "MY NAME IS DHRUMIN KHATRI";
	char	ch = '\n';

	real = printf ("%s %x%c", str, -50, ch);
	img = ft_printf("%s %x%c", str, -50, ch);
	ft_printf("PRINTF : %d\tFT_PRINTF : %d", real, img);
	return (0);
}
