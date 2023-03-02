/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonneva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:03:10 by rbonneva          #+#    #+#             */
/*   Updated: 2023/02/28 00:56:15 by rbonneva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/mlx_norm.h"
#include <stdlib.h>

t_image	*mlx_ext_new_image(void *mlx_ptr, int width, int height)
{
	void	*img_ptr;
	t_image	*new_image;

	img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (img_ptr == NULL)
		return (NULL);
	new_image = malloc(sizeof(t_image));
	if (new_image == NULL)
	{
		mlx_destroy_image(mlx_ptr, img_ptr);
		return (NULL);
	}
	new_image->img = img_ptr;
	new_image->addr = mlx_get_data_addr(new_image->img, \
										&new_image->bits_per_pixel, \
										&new_image->width, \
										&new_image->endian);
	new_image->bits_per_pixel /= 8;
	new_image->size = (width * height * new_image->bits_per_pixel);
	return (new_image);
}

void	mlx_delete_image(void *mlx_ptr, t_image **image)
{
	mlx_destroy_image(mlx_ptr, (*image)->img);
	free(*image);
	*image = NULL;
}
