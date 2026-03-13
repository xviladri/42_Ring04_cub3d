/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:51:27 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 19:50:51 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* 1. Elige la textura correcta segun la cara del muro */
static t_tex	*get_texture(t_map *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (&data->tex_e);
		return (&data->tex_w);
	}
	else
	{
		if (ray->dir_y > 0)
			return (&data->tex_s);
		return (&data->tex_n);
	}
}

/* 2. Calcula en que punto horizontal (X) de la textura estamos golpeando */
static int calculate_tex_x(t_map *data, t_ray *ray, t_tex *tex)
{
    double wall_x;
    int    tex_x;

    if (ray->side == 0)
        wall_x = data->player.pos_y + ray->perp_wall_dist * ray->dir_y;
    else
        wall_x = data->player.pos_x + ray->perp_wall_dist * ray->dir_x;
    wall_x -= floor(wall_x);
    tex_x = (int)(wall_x * (double)tex->width);
    if (ray->side == 0 && ray->dir_x < 0)
        tex_x = tex->width - tex_x - 1;
        
    if (ray->side == 1 && ray->dir_y > 0)
        tex_x = tex->width - tex_x - 1;

    return (tex_x);
}

/* 3. Funcion auxiliar que hace el bucle de pintado (Norminette OK) */
static void	paint_pixels(t_map *data, t_ray *ray, int x, int tex_x)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;
	t_tex	*t;

	t = get_texture(data, ray);
	step = 1.0 * t->height / ray->line_height;
	tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (t->height - 1);
		tex_pos += step;
		put_pixel_to_image(data->imgs, x, y, *(unsigned int *)(t->addr
				+ (tex_y * t->line_len + tex_x * (t->bpp / 8))));
		y++;
	}
}

/* 4. Calcula la altura de la pared en pantalla y llama a pintar */
static void	draw_textured_line(t_map *data, t_ray *ray, int x)
{
	t_tex	*t;
	int		tex_x;

	t = get_texture(data, ray);
	tex_x = calculate_tex_x(data, ray, t);
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT;
	paint_pixels(data, ray, x, tex_x);
}

/* 5. Bucle principal: 1 rayo por cada columna de pixeles en pantalla */
void	render_walls(t_map *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(data, &ray, x);
		perform_dda(data, &ray);
		draw_textured_line(data, &ray, x);
		x++;
	}
}
