/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:39 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: move cursor
 */

#include	"incendie.h"

void		move_cursor(t_average		*var,
			    int			add_x,
			    int			add_y)
{
  var->pos_i.x += add_x;
  var->pos_i.y += add_y;
}
