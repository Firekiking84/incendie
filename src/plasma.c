#include		<lapin.h>
#include		"incendie.h"

void			plasma(t_window		*win)
{
  unsigned int		palette[129];
  int			i;
  int			limit;
  int			pick;
  unsigned int		*tab;

  limit = (win->size.x * win->size.y) - 1;
  fill_palette_plasma(&palette[0]);
  tab = win->px->pixels;
  i = 0;
  while (i < limit)
    {
      pick = cos(i) * 128;
      if (pick > 128)
	pick = 128;
      if (pick < 0)
	pick *= -1;
      tab[i] = palette[pick];
      i += 1;
    }
  bunny_blit(&win->win->buffer, &win->px->clipable, &win->origin);
  bunny_display(win->win);  
}
