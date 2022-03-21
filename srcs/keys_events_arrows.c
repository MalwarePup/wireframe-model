/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_events_arrows.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:22:42 by ple-stra          #+#    #+#             */
/*   Updated: 2022/03/21 15:55:24 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_on_arrowl_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ARROW_LEFT key pressed \n");
	fdf->draw.screentx -= fdf->draw.fscreen;
}

void	ft_on_arrowr_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ARROW_RIGHT key pressed \n");
	fdf->draw.screentx += fdf->draw.fscreen;
}

void	ft_on_arrowt_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ARROW_TOP key pressed \n");
	fdf->draw.screenty -= fdf->draw.fscreen;
}

void	ft_on_arrowd_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ARROW_DOWN key pressed \n");
	fdf->draw.screenty += fdf->draw.fscreen;
}
