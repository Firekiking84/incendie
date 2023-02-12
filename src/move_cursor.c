#include		"incendie.h"

void		move_cursor(t_average		*var,
			    int			add_x,
			    int			add_y)
{
  var->pos_i.x += add_x;
  var->pos_i.y += add_y;
}
