#include		"incendie.h"
#include		<lapin.h>
#include		<unistd.h>

void			def_fire(unsigned int		*palette,
				 t_window		*win)
{
  int			n_line;
  int			n_raw;
  t_bunny_position	pos;
  int			n_pos;

  n_line = 1;
  while (n_line < win->size.y)
    {
      pos.y = win->size.y - n_line - 1;
      n_raw = 0;
      while (n_raw < win->size.x)
	{
	  pos.x = win->size.x - n_raw;
	  n_pos = ((pos.y + 1) * win->size.x) + pos.x;
	  set_pixel(win->px, &pos, average_color(n_pos,(win->size.x * win->size.y), win->px, 1));
	  n_raw += 1;
	}
      n_line += 1;
    }
}
