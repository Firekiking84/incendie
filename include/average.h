#ifndef			_AVERAGE_

#define			_AVERAGE_

#include		<lapin.h>

typedef struct		s_average{
  t_bunny_color		px_col;
  t_bunny_color		average_col;
  t_bunny_position	pos_i;
  int			npos;
  int			width;
  unsigned int		*tableau;
  int			limit;
}			t_average;

#endif
