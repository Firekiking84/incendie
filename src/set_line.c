/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:40 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: set_line
 */

#include		<lapin.h>
#include		"incendie.h"

static void		reverse(struct line_properties		*draw)
{
    int			x;
    int			y;

    if (draw->xtrm_a.x > draw->xtrm_b.x)
      {
        x = draw->xtrm_a.x;
        y = draw->xtrm_a.y;
        draw->xtrm_a.x = draw->xtrm_b.x;
        draw->xtrm_a.y = draw->xtrm_b.y;
        draw->xtrm_b.x = x;
        draw->xtrm_b.y = y;
    }
}

static void		verticale_line(struct line_properties	*draw,
				       t_window			*info)
{
    int			y;
    int			i;
    t_bunny_position	pixel_pos;

    y = draw->xtrm_a.y;
    pixel_pos.x = draw->xtrm_a.x;
    if (draw->xtrm_a.y < draw->xtrm_b.y)
        i = 1;
    else
        i = -1;
    while (y != draw->xtrm_b.y)
      {
        pixel_pos.y = y;
        set_pixel(info->px, &pixel_pos, draw->color);
        y += i;
      }
}

static void		horizontale_line(struct line_properties *draw,
					 t_window		*info)
{
    int			x;
    t_bunny_position	pixel_pos;

    x = draw->xtrm_a.x;
    pixel_pos.y = draw->xtrm_a.y;
    while (x != draw->xtrm_b.x)
      {
        pixel_pos.x = x;
        set_pixel(info->px, &pixel_pos, draw->color);
        x += 1;
    }
}

void			set_line(struct line_properties		*draw,
				 t_window     			*info)
{
    reverse(draw);
    if (draw->xtrm_a.x == draw->xtrm_b.x)
        verticale_line(draw, info);
    else if (draw->xtrm_a.y == draw->xtrm_b.y)
        horizontale_line(draw, info);
    else
        diagonale_line(draw, info);
}
