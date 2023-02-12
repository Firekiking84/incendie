/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:41 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: set_pixel
 */

#include		<lapin.h>

void			set_pixel(t_bunny_pixelarray	*px,
				  t_bunny_position	*pos,
				  unsigned int		color)
{
  unsigned int		*tableau;
  int			npos;
  int			limit;
  int			width;
  int			height;

  width = px->clipable.clip_width;
  height = px->clipable.clip_height;
  limit = width * height;
  tableau = px->pixels;
  npos = (pos->y * width) + pos->x;
  if (npos <= limit && npos > 0)
    tableau[npos] = color;
  else
    return;
}
