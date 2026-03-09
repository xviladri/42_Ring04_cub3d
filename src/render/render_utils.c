/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:27:06 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 18:28:24 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//1. Ponemos 1 pixel directamente en la memoria de la imagen
void	put_pixel_to_image(t_img_d *img, int x, int y, int color)
{
	char	*dst;
	// Protegemos si intentamos pintar fuera de la ventana --> no hacemos nada
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	// Calculamos la direccion de memoria exacta del pixel
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	// Escribimos el color en esa direccion de memoria
	*(unsigned int *)dst = color;
}
