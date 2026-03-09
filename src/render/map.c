/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:51:27 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 19:13:02 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//Funcion auxiliar a render_walls que calcula la altura y dibuja la linea vertical
static void	draw_vertical_line(t_map *data, t_ray *ray, int x)
{
	int	y;
	int	color;

	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT;
	if (ray->side == 1)
		color = 0x555555;
	else
		color = 0xAAAAAA;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		put_pixel_to_image(data->imgs, x, y, color);
		y++;
	}
}

// Bucle principal: 1 rayo por cada columna de pixeles en pantalla
void	render_walls(t_map *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(data, &ray, x);
		perform_dda(data, &ray);
		draw_vertical_line(data, &ray, x);
		x++;
	}
}
