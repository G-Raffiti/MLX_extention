/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonneva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:18:34 by rbonneva          #+#    #+#             */
/*   Updated: 2023/02/27 20:20:49 by rbonneva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_STRUCT_H
# define MLX_STRUCT_H

/**
 * Image Struct
 * \param [void *] img Ptr to the Mlx Image.
 * \param [char *] addr Ptr to the string containing all the colors in the
 * image.
 * \param [void *] bit_pet_pixel should be divided by 8 if you are using TRGB
 * colors.
 * \param [void *] width Image width.
 * \param [void *] endian data byte order, LSBFirst, MSBFirst
 */
typedef struct s_image
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				width;
	int				size;
	int				endian;
}					t_image;

/**
 * Color Struct with T R G B variables
 */
typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	t;
}					t_color;
#endif
