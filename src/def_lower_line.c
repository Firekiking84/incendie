#include		"incendie.h"
#include		<time.h>
#include		<stdlib.h>

void			def_lower_line(unsigned int		*palette,
				       t_window			*win)
{
  int			n_line;
  int			n_raw;
  t_bunny_position	pos;
  
  srand(time(NULL));
  n_line = 0;
  while (n_line < 2)
    {
      n_raw = 0;
      pos.y = win->size.y - n_line;
      while (n_raw < win->size.x)
	{
	  pos.x = win->size.x - n_raw;
	  set_pixel(win->px, &pos, palette[(rand() % 129)]);
	  n_raw += 1;
	}
      n_line += 1;
    }
}
