#include "../inc/cub3d.h"

// Crea UNA imagen en blanco (el "lienzo" donde dibujarás cada frame)
// mlx_get_data_addr te da el puntero directo a los píxeles en RAM
void	create_render_image(t_map *data)
{
	// Reservar array de 5 imágenes: [0]=render, [1]=NO, [2]=SO, [3]=WE, [4]=EA
	data->imgs = malloc(sizeof(t_img_d) * 5);
	if (!data->imgs)
		free_and_exit(data, "Error: malloc imgs failed");

	// Imagen de render (donde dibujas el frame)
	data->imgs[0].img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->imgs[0].img_ptr)
		free_and_exit(data, "Error: mlx_new_image() failed");

	// Esto te da acceso a los píxeles como un array de bytes
	data->imgs[0].addr = mlx_get_data_addr(
		data->imgs[0].img_ptr,
		&data->imgs[0].bpp,        // bits por pixel (normalmente 32)
		&data->imgs[0].line_length, // bytes por fila
		&data->imgs[0].endian       // orden de bytes
	);
}

// Carga UNA textura .xpm a una t_img_d
void	load_texture(t_map *data, t_img_d *img, char *path)
{
	img->img_ptr = mlx_xpm_file_to_image(
		data->mlx_ptr, path,
		&img->width, &img->height
	);
	if (!img->img_ptr)
		free_and_exit(data, "Error: failed to load texture");

	img->addr = mlx_get_data_addr(
		img->img_ptr,
		&img->bpp,
		&img->line_length,
		&img->endian
	);
}

// Carga las 4 texturas (NO, SO, WE, EA)
void	load_textures(t_map *data)
{
	load_texture(data, &data->imgs[1], data->cardinal.no); // Norte
	load_texture(data, &data->imgs[2], data->cardinal.so); // Sur
	load_texture(data, &data->imgs[3], data->cardinal.we); // Oeste
	load_texture(data, &data->imgs[4], data->cardinal.ea); // Este
}

// Llama a todo
void	init_images(t_map *data)
{
	create_render_image(data);
	load_textures(data);
}
