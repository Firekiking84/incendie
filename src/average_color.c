#include		<lapin.h>
#include		"incendie.h"

static void		behind(t_average			*var,
			       int				neighbour)
{
  int			i;

  i = 0;
  while (i < neighbour)
    {
      move_cursor(var, -1, 0);
      calcul_and_apply(var);
      i += 1;
    }
  reset_position(i, var, 0);
}

static void		front(t_average				*var,
			      int				neighbour)
{
  int			i;

  i = 0;
  while (i < neighbour)
    {
      move_cursor(var, 1, 0);
      calcul_and_apply(var);
      i += 1;
    }
  reset_position(i, var, 1);
}

static void		below(t_average				*var,
			      int				neighbour)
{
  int			i_y;
  int			i_x;

  i_y = 1;
  move_cursor(var, -(neighbour), -1);
  while (i_y < neighbour)
    {
      i_x = 1;
      while (i_x < (neighbour * 2))
	{
	  move_cursor(var, 1, 0);
	  calcul_and_apply(var);
	  i_x += 1;
	}
      move_cursor(var, -(neighbour * 2), -1);
      i_y += 1;
    }
  reset_position(neighbour, var, 2);
}

static void		top(t_average				*var,
			    int					neighbour)
{
  int			i_y;
  int			i_x;

  i_y = 1;
  move_cursor(var, -(neighbour), 1);
  while (i_y < neighbour)
    {
      i_x = 1;
      while (i_x < (neighbour * 2))
	{
	  move_cursor(var, 1, 0);
	  calcul_and_apply(var);
	  i_x += 1;
	}
      move_cursor(var, -(neighbour * 2), 1);
      i_y += 1;
    }
  reset_position(neighbour, var, 3);
}

unsigned int		average_color(int			i,
				      int			limit,
				      t_bunny_pixelarray	*px,
				      int			neighbour)
{
  t_average		var;

  var.tableau = px->pixels;
  var.width = px->clipable.clip_width;
  var.limit = limit;
  var.pos_i.y = i / var.width;
  var.pos_i.x = i % var.width;
  var.average_col.full = var.tableau[i];
  behind(&var, neighbour);
  front(&var, neighbour);
  below(&var, neighbour);
  top(&var, neighbour);
  return(var.average_col.full);
}
