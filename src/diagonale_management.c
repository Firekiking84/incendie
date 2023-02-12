/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:33 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: manage shape for diagonale skeleton
 */

#include		<lapin.h>
#include		"incendie.h"

static int		check_status(int				a,
				     int				b,
				     int				sens)
{
  int			result;

  result = 0;
  if (sens == 1)
    {
      if (a > b)
	result = 1;
    }
  else
    {
      if (a < b)
	result = 1;
    }
  return(result);
}

static void		diagonale_x(t_bunny_position			*pos,
				    t_window				*win,
				    unsigned int			*palette)
{
  float			ratio;
  int			x;
  int			y;
  t_bunny_position	pixel_pos;

  x = pos[0].x;
  while (x <= pos[1].x)
    {
      ratio = get_ratio(pos[0].x, pos[1].x, x);
      y = get_value(pos[0].y, pos[1].y, ratio);
      pixel_pos.x = x;
      pixel_pos.y = y;
      draw_shapes(pixel_pos, win, palette);
      x += 1;
    }
}

static void		diagonale_y(t_bunny_position			*pos,
				    t_window				*win,
				    unsigned int		        *palette)
{
  float			ratio;
  int			sens;
  int			isFinish;
  int			y;
  int			x;
  t_bunny_position	pixel_pos;

  isFinish;
  y = pos[0].y;
  sens = sens_finder(pos[0].y, pos[1].y);
  while (isFinish != 1)
    {
      ratio = get_ratio(pos[0].y, pos[1].y, y);
      ratio = val_abs_f(ratio);
      x = get_value(pos[0].x, pos[1].y, ratio);
      pixel_pos.x = x;
      pixel_pos.y = y;
      draw_shapes(pixel_pos, win, palette);
      y += sens;
      isFinish = check_status(y, pos[1].y, sens);
    }
}
  

void			diagonale_management(t_bunny_position		*pos,
					     t_window			*win,
					     unsigned int		*palette)
{
  int			norme_x;
  int			norme_y;

  norme_x = norme(pos[0].x, pos[1].x);
  norme_y = norme(pos[0].y, pos[1].y);
  if (norme_x >= norme_y)
    diagonale_x(pos, win, palette);
  else
    diagonale_y(pos, win, palette);
}
