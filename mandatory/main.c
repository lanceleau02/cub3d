/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:07:29 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/27 15:44:25 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init(t_program *data)
{
	init_textures(data);
	init_colors(data);
	if (init_data(data) == 1 || load_png(data) == 1 || init_mlx(data) == 1)
		return (1);
	init_player(data);
	init_screen(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_program	data;

	data.fd = get_fd(argv[1]);
	if (data.fd == -1 || pre_parsing(argc, argv) == 1)
		return (1);
	if (init(&data) == 1)
		return (1);
	if (init_images(&data) == 1)
	{
		ft_putstr_fd("cub3d: Invalid textures.\n", 2);
		return (1);
	}
	mlx_loop_hook(data.mlx, key_hook, &data);
	mlx_image_to_window(data.mlx, data.images.main_img, 0, 0);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}
