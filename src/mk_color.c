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
