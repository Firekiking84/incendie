/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:32 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: (Broken) Draw a gradient of grey in the background
 */

#include		"incendie.h"
#include		<lapin.h>

void			def_smoke(t_window		*win)
{
  int			npos;
  unsigned char		grey;
  float			step;
  int			n_line;
  unsigned int		*tab;
  int			range;

  step = (float)255 / win->size.y;
  npos = win->size.x * win->size.y - 1;
  n_line = 0;
  tab = win->px->pixels;
  range = 255;
  while (npos >= 0)
    {
      if (npos > 0 && (npos % win->size.x) == 0)
	n_line += 1;
      if ((step * n_line) >= 1)
	range = (int)255 - (step * n_line);
      grey = rand() % range;
      tab[npos] = mk_color(grey, grey, grey, 1);
      npos -= 1;
    }
}
