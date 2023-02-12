#include <lapin.h>
#include "incendie.h"

static int			check_status(int			a,
					     int			b,
					     int			sens)
{
    int				result;

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

static void			diagonale_x(struct line_properties	*draw,
					    t_window			*info)
{
    float			ratio;
    int				x;
    int				y;
    t_bunny_position		pos;

    x = draw->xtrm_a.x;
    while (x <= draw->xtrm_b.x )
      {
        ratio = get_ratio(draw->xtrm_a.x, draw->xtrm_b.x, x);
        y = get_value(draw->xtrm_a.y, draw->xtrm_b.y, ratio);
        pos.x = x;
        pos.y = y;
        set_pixel(info->px, &pos, draw->color);
        x += 1;
      }
}

static void			diagonale_y(struct line_properties	*draw,
					    t_window			*info)
{
    float			ratio;
    int				sens;
    int				isFinish;
    int				y;
    int				x;
    t_bunny_position		pos;

    isFinish = 0;
    y = draw->xtrm_a.y;
    sens = sens_finder(draw->xtrm_a.y, draw->xtrm_b.y);
    while (isFinish != 1)
      {
        ratio = get_ratio(draw->xtrm_a.y, draw->xtrm_b.y, y);
        ratio = val_abs_f(ratio);
        x = get_value(draw->xtrm_a.x, draw->xtrm_b.x, ratio);
        pos.x = x;
        pos.y = y;
        set_pixel(info->px, &pos, draw->color);
        y += sens;
        isFinish = check_status(y, draw->xtrm_b.y, sens);
      }
}

void				diagonale_line(struct line_properties	*draw,
					       t_window			*info)
{
    int				norme_x;
    int				norme_y;

    norme_x = norme(draw->xtrm_a.x, draw->xtrm_b.x);
    norme_y = norme(draw->xtrm_a.y, draw->xtrm_b.y);
    if (norme_x >= norme_y)
      diagonale_x(draw, info);
    else
      diagonale_y(draw, info);
}
