/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:38 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: make color
 */

#include	<lapin.h>

unsigned int	mk_color(unsigned char r,
			 unsigned char g,
			 unsigned char b,
			 unsigned char a)
{
  t_bunny_color col;

  col.full = 0;
  col.argb[0] = r;
  col.argb[1] = g;
  col.argb[2] = b;
  col.argb[3] = a;
  return(col.full);
}
