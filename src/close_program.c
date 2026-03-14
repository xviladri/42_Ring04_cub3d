/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:39:50 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 19:20:57 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	free_texture(t_map *data, t_tex *tex)
{
	if (tex->img_ptr)
		mlx_destroy_image(data->mlx_ptr, tex->img_ptr);
}

static void	empty_gnl(int fd)
{
	char	*tmp;

	if (fd > 0)
	{
		tmp = get_next_line(fd);
		while (tmp != NULL)
		{
			free(tmp);
			tmp = get_next_line(fd);
		}
		close(fd);
	}
}

void	free_and_exit(t_map *data, char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	if (data->cardinal.no)
		free(data->cardinal.no);
	if (data->cardinal.so)
		free(data->cardinal.so);
	if (data->cardinal.we)
		free(data->cardinal.we);
	if (data->cardinal.ea)
		free(data->cardinal.ea);
	if (data->map)
		free_matrix(data->map);
	empty_gnl(data->fd);
	exit(1);
}

static void	free_graphics(t_map *data)
{
	if (!data->mlx_ptr)
		return ;
	free_texture(data, &data->tex_n);
	free_texture(data, &data->tex_s);
	free_texture(data, &data->tex_e);
	free_texture(data, &data->tex_w);
	if (data->imgs && data->imgs->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->imgs->img_ptr);
	if (data->imgs)
		free(data->imgs);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	close_window(t_map *data)
{
	free_graphics(data);
	if (data->cardinal.no)
		free(data->cardinal.no);
	if (data->cardinal.so)
		free(data->cardinal.so);
	if (data->cardinal.we)
		free(data->cardinal.we);
	if (data->cardinal.ea)
		free(data->cardinal.ea);
	if (data->map)
		free_matrix(data->map);
	exit(0);
	return (0);
}
