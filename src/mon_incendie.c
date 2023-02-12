/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:38 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: My version of the project incendie
 */

#include		"incendie.h"
#include		<lapin.h>
#include		<unistd.h>

static void		blur(t_window			*win,
			     int			range)
{
  int			i;
  int			limit;
  unsigned int		*tableau;

  i = 0;
  limit = win->size.x * win->size.y;
  tableau  = win->px->pixels;
  while (i < limit)
    {
      tableau[i] = average_color(i, limit, win->px, range);
      i += 1;
    }
}

void			mon_incendie(t_window		*win)
{
  unsigned int	        palette[128];
  unsigned int		color;
  int			i;

  i = 0;
  fill_palette(&palette[0]);
  init_pixelarray(win, 0);
  while (i < 50)
    {
      def_fire_body(win, &palette[0]);
      blur(win, 5);
      blur(win, 2);
      i += 1;
    }
  i = 0;
  while (i < 30)
    {
      def_fire_body(win, &palette[0]);
      blur(win, 5);
      blur(win, 2);
      i += 1;
      bunny_blit(&win->win->buffer, &win->px->clipable, &win->origin);
      bunny_display(win->win);
    }
}
  
