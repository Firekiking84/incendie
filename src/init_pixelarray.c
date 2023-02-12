#include		"incendie.h"
#include	        <lapin.h>

void			init_pixelarray(t_window		*win,
					unsigned int		color)
{
  int			limit;
  int			i;
  unsigned int		*tab;

  limit = win->size.x * win->size.y;
  i = 0;
  tab = win->px->pixels;
  while (i < limit)
    {
      tab[i] = color;
      i += 1;
    }
}
