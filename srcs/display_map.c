/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:55:02 by ple-stra          #+#    #+#             */
/*   Updated: 2022/05/09 16:43:51 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_reframe(t_fdf *fdf)
{
	ft_create_new_fdf_img(fdf);
	ft_draw(fdf);
	ft_set_new_img_to_screen(fdf);
	if (KDEBUG)
		ft_print_draw_debug_info(fdf);
}

static void	ft_init_mlx(t_fdf *fdf)
{
	fdf->mlx.mlx = mlx_init();
	if (!fdf->mlx.mlx)
		ft_exit(*fdf, ft_perror(ERR_FAILED_INIT_MLX));
}

static void	ft_create_window(t_fdf *fdf)
{
	t_mlx	*mlx;

	mlx = &fdf->mlx;
	mlx_get_screen_size(mlx->mlx, &mlx->win_width, &mlx->win_height);
	mlx->win_width /= 2;
	mlx->win_height /= 2;
	mlx->window = mlx_new_window(mlx->mlx, mlx->win_width, mlx->win_height,
			PROGRAM_NAME);
	if (!mlx->window)
		ft_exit(*fdf, ft_perror(ERR_FAILED_OP_WIN_MLX));
}

void	ft_display_map(t_fdf *fdf)
{
	t_mlx	*mlx;

	ft_init_mlx(fdf);
	ft_create_window(fdf);
	ft_init_fdf_draw_helpers(fdf);
	mlx = &fdf->mlx;
	ft_reframe(fdf);
	mlx_key_hook(mlx->window, ft_on_keypressed, fdf);
	mlx_hook(mlx->window, 17, 0, ft_on_cross_clicked, fdf);
	mlx_loop(mlx->mlx);
}
