#ifndef			_WINDOW_

#define			_WINDOW_

#include		<lapin.h>

typedef struct		s_window {
  t_bunny_position	origin;
  t_bunny_window	*win;
  t_bunny_pixelarray	*px;
  t_bunny_position	size;
}			t_window;

#endif
