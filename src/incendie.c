/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:36 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: (Broken) Use the script give in the rules to do fire
 */

#include			"incendie.h"
#include			<unistd.h>
#include			<lapin.h>

void				incendie(t_window		*win)
{
  unsigned int			palette[129];
  unsigned int			color;

  color = mk_color(0, 255, 0, 1);
  fill_palette(&palette[0]);
  init_pixelarray(win, color);
  def_lower_line(&palette[0], win);
  def_fire(&palette[0], win);
}
