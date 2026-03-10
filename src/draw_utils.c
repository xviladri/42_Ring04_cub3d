#include "../inc/cub3d.h"

// Escribe UN píxel de color 'color' en la posición (x, y) de la imagen
// color = 0x00RRGGBB en hexadecimal (ej: 0x00FF0000 = rojo puro)
void	my_pixel_put(t_img_d *img, int x, int y, int color)
{
	char	*dst;

	// Protección de límites (evita seg fault)
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	// Calculamos la dirección exacta del píxel en memoria:
	// cada fila tiene 'line_length' bytes, y cada píxel tiene bpp/8 bytes
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

// Convierte R, G, B a un entero de color que entiende MLX
int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

// Obtiene el color de UN píxel de una textura en (x, y)
int	get_texture_pixel(t_img_d *tex, int x, int y)
{
	char	*src;

	src = tex->addr + (y * tex->line_length + x * (tex->bpp / 8));
	return (*(unsigned int *)src);
}
