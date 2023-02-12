/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:34 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: Draw each layer of the fire's body
 */

#include			"incendie.h"
#include			<lapin.h>
#include			<stdlib.h>
#include			<time.h>

static void			first_layer(t_bunny_position		pixel_pos,
					    t_window			*win,
					    unsigned int		*palette)
{
  int				len;
  int				i;

  len = rand() % 100;
  if (len < 10)
    len = 10;
  i = 0;
  while (i < len)
    {
      pixel_pos.x += 1;
      set_pixel(win->px, &pixel_pos, palette[(rand() % 33)]);
      i += 1;
    }
  len = rand() % 100;
  if (len < 10)
    len = 10;
  i = 0;
  while (i < len)
    {
      pixel_pos.x -= 1;
      set_pixel(win->px, &pixel_pos, palette[(rand() % 33)]);
      i += 1;
    }
}

static void			second_layer(t_bunny_position		pixel_pos,
					     t_window			*win,
					     unsigned int		*palette)
{
  int				len;
  int				i;
  int				rand_value;
   
  init_layer_value(&len, &i, &rand_value, 60);
  while (i < len)
    {
      pixel_pos.x += 1;
      while (rand_value < 32 && rand_value > 65)
	rand_value = rand() % 65;
      set_pixel(win->px, &pixel_pos, palette[rand_value]);
      i += 1;
    }
  init_layer_value(&len, &i, &rand_value, 60);
  while (i < len)
    {
      pixel_pos.x -= 1;
      while (rand_value < 32 && rand_value > 65)
	rand_value = rand() % 65;
      set_pixel(win->px, &pixel_pos, palette[rand_value]);
      i += 1;
    }
}

static void			third_layer(t_bunny_position		pixel_pos,
					    t_window			*win,
					    unsigned int		*palette)
{
  int				len;
  int				i;
  int				rand_value;

  init_layer_value(&len, &i, &rand_value, 5);
  while (i < len)
    {
      pixel_pos.x += 1;
      while (rand_value < 64)
	rand_value = rand() % 97;
      set_pixel(win->px, &pixel_pos, palette[rand_value]);
      i += 1;
    }
  init_layer_value(&len, &i, &rand_value, 5);
  while (i < len)
    {
      pixel_pos.x -= 1;
      while (rand_value < 64)
	rand_value = rand() % 97;
      set_pixel(win->px, &pixel_pos, palette[rand_value]);
      i += 1;
    }
}

static void			fourth_layer(t_bunny_position		pixel_pos,
					     t_window			*win,
					     unsigned int		*palette)
{
  int				len;
  int				i;
  int				rand_value;

  init_layer_value(&len, &i, &rand_value, 2);
  while (i < len)
    {
      pixel_pos.x += 1;
      while (rand_value < 97)
	rand_value = rand() % 129;
      set_pixel(win->px, &pixel_pos, palette[rand_value]);
      i += 1;
    }
  init_layer_value(&len, &i, &rand_value, 2);
  while (i < len)
    {
      pixel_pos.x -= 1;
      while (rand_value < 97)
	rand_value = rand() % 129;
      set_pixel(win->px, &pixel_pos, palette[rand_value]);
      i += 1;
    }
} 

void				draw_shapes(t_bunny_position		pixel_pos,
					    t_window			*win,
					    unsigned int		*palette)
{
  second_layer(pixel_pos, win, palette);
  first_layer(pixel_pos, win, palette);
  third_layer(pixel_pos, win, palette);
  fourth_layer(pixel_pos, win, palette);
}
