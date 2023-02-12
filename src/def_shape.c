#include		"incendie.h"
#include		<lapin.h>

static void		reverse(t_bunny_position			*pos)
{
  t_bunny_position	temp;

  if (pos[0].x > pos[1].x)
    {
      temp.x = pos[0].x;
      temp.y = pos[0].y;
      pos[0].x = pos[1].x;
      pos[0].y = pos[1].y;
      pos[1].x = temp.x;
      pos[1].y = temp.y;
    }
}

static void		vertical_management(t_bunny_position		*pos,
					     t_window			*win,
					     unsigned int		*palette)
{
  int			y;
  t_bunny_position	pixel_pos;

  y = pos[0].y;
  pixel_pos.x = pos[0].x;
  while (y != pos[1].y)
    {
      pixel_pos.y = y;
      draw_shapes(pixel_pos, win, palette);
      y -= 1;
    }
}
      

void			def_shape(t_bunny_position			*pos,
				  t_window				*win,
				  unsigned int				*palette)
{
  reverse(pos);
  if (pos[0].x == pos[1].x)
    vertical_management(pos, win, palette);
  else
    diagonale_management(pos, win, palette);
}
