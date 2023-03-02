/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonneva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:16:06 by rbonneva          #+#    #+#             */
/*   Updated: 2023/02/27 21:52:47 by rbonneva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/mlx_norm.h"
#include "../../incs/mlx_struct.h"

int	get_color(t_color color)
{
	return (*(int *)(unsigned char [4]){color.b, color.g, color.r, color.t});
}

void	mlx_pixel_put_to_image(t_image *image, int x, int y, t_color color)
{
	char	*dst;
	int		pixel;

	pixel = y * image->width + x * image->bits_per_pixel;
	if (pixel > image->size)
		return ;
	dst = image->addr + pixel;
	*(unsigned int *)dst = get_color(color);
}
