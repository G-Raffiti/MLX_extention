/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_norm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonneva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:38:59 by rbonneva          #+#    #+#             */
/*   Updated: 2023/03/02 19:49:28 by rbonneva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_NORM_H
# define MLX_NORM_H
# include "mlx_struct.h"

/*
 ******************************************************************************
 **                               INITIALIZATION                             **
 ******************************************************************************
*/

/**
 * Initializes a new Lib_MLX Instance.
 * @returns Ptr to the MLX handle or NULL on failure.
 */
void	*mlx_init(void);

/**
 * Initializes and Display a new Window.
 * @param[void *] mlx_ptr The Ptr to the MLX Instance.
 * @param[in] width The width of the window.
 * @param[in] height The height of the window.
 * @param[in] title The title of the window.
 * @returns Ptr to the new Window or NULL on failure.
 */
void	*mlx_new_window(void *mlx_ptr, int width, int height, char *title);
/**
 * TODO:VERIF !\n
 * Reset all the Pixels in the given Window
 * @param[void *] mlx_ptr The Ptr to the MLX Instance.
 * @param[void *] win_ptr The Ptr to the Window to clear.
 * @return Nothing
 */
int		mlx_clear_window(void *mlx_ptr, void *win_ptr);

/*
 ******************************************************************************
 **                                 LOOP                                     **
 ******************************************************************************
*/
/**
 * Initializes the rendering of MLX, this function won't return until
 * mlx_close_window is called, meaning it will loop until the user requests that
 * the window should close or the mlx_loop_end is called
 * @param[in] mlx The MLX instance handle.
 */
int		mlx_loop(void *mlx_ptr);

/**
 * Stops the rendering of MLX.
 * @param[in] mlx The MLX instance handle.
 */
int		mlx_loop_end(void *mlx_ptr);

/*
 ******************************************************************************
 **                                 IMAGE                                    **
q ******************************************************************************
*/

/**
 * This function is depreciated use mlx_pixel_put_to_image instead
 */
int		mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

/**
 * Color the pixel at the given position (x,y)
 * @param [t_image] image Ptr to the Image to draw on
 * @param [int] x X position relative to the image.
 * @param [int] y Y position relative to the image.
 * @param [int] color
 */
void	mlx_pixel_put_to_image(t_image *image, int x, int y, t_color color);

/**
 * Creates and allocates a new image buffer.
 * @param[void*] mlx_ptr The MLX instance handle.
 * @param[in] width The desired width of the image.
 * @param[in] height The desired height of the image.
 * @return Pointer to the image buffer, if it failed to allocate then NULL.
 */
void	*mlx_new_image(void *mlx_ptr, int width, int height);

/**
 * Creates and allocates a new image and set a Struct to handel basic infos.
 * @param[void*] mlx_ptr The MLX instance handle.
 * @param[in] width The desired width of the image.
 * @param[in] height The desired height of the image.
 * @return Pointer to the image struct, if it failed to allocate then NULL.
 */
t_image	*mlx_ext_new_image(void *mlx_ptr, int width, int height);

/**
 * Get all the data from the Image_Ptr and set them to the params
 * @param img_ptr Ptr to the image buffer
 * @param bits_per_pixel Set the bits used to encode 1 pixel
 * @param size_line width of the Image
 * @param endian data byte order, LSBFirst, MSBFirst
 * @return The NULL terminated char* addr that contain all the colors of the
 * image
 */
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			int *size_line, int *endian);

/**
 * Draws a new instance of an image, it will then share the same
 * pixel buffer as the image.
 * WARNING: Try to display as few images on the window as possible,
 * drawing too many images will cause a loss in peformance!
 * @param[void *] mlx_ptr The MLX instance handle.
 * @param[void *] win_ptr The Ptr to the Window to put the image on.
 * @param[void *] img_ptr The image to draw on the screen.
 * @param[in] x The X position.
 * @param[in] y The Y position.
 * @return Nothing
 */
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
			int x, int y);

/**
 * @return the Color passed as a RGB int color
 */
int		mlx_get_color_value(void *mlx_ptr, int color);

/*
 ******************************************************************************
 **                                 EVENT                                    **
 ******************************************************************************
*/

int		mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
int		mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(),
			void *param);
int		mlx_do_key_autorepeatoff(void *mlx_ptr);
int		mlx_do_key_autorepeaton(void *mlx_ptr);
int		mlx_do_sync(void *mlx_ptr);
int		mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr, int *x, int *y);
int		mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);
int		mlx_mouse_hide(void *mlx_ptr, void *win_ptr);
int		mlx_mouse_show(void *mlx_ptr, void *win_ptr);

/*
 ******************************************************************************
 **                                 STRING                                   **
 ******************************************************************************
*/

int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,
			char *string);
void	mlx_set_font(void *mlx_ptr, void *win_ptr, char *name);

/*
 ******************************************************************************
 **                                 XPM                                      **
 ******************************************************************************
*/

void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
			int *width, int *height);
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
			int *width, int *height);
t_image	*mlx_ext_xpm_file_to_image(void *mlx_ptr, char *filename,
			int width, int height);

/*
 ******************************************************************************
 **                                 DESTROY                                  **
 ******************************************************************************
*/

/**
 * Notifies MLX that it should stop rendering and exit the main loop.
 * This is not the same as terminate, this simply tells MLX to close the window.
 * @param[void*] mlx_ptr The MLX instance handle.
 * @param[void*] win_ptr The Window to close.
 * @returns Nothing
 */
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);

/**
 * Deleting an image will remove it from the render queue as well as any and all
 * instances it might have.
 * @param[void*] mlx_ptr The MLX instance handle.
 * @param[void*] img_ptr The image to delete.
 * @returns Nothing
 */
int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);

/**
 * Deleting an image will remove it from the render queue as well as any and all
 * instances it might have. Additionally, free and set the pointer to NULL.
 * @param[void*] mlx_ptr The MLX instance handle.
 * @param[t_image] image The structure image to delete.
 */
void	mlx_delete_image(void *mlx_ptr, t_image **image);

int		mlx_destroy_display(void *mlx_ptr);

////////////////////////////////////////////////////////////////////////////////
//                                  SCREEN                                    //
////////////////////////////////////////////////////////////////////////////////
int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

#endif
