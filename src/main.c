#include		<lapin.h>
#include		"incendie.h"
#include		<unistd.h>

int			main(void)
{
  t_window		incendie;
  t_window		plasma_screen;

  incendie.size.x = 500;
  incendie.size.y = 500 + 100;
  incendie.origin.x = 0;
  incendie.origin.y = 0;
  plasma_screen.size.x = 500;
  plasma_screen.size.y = 500;
  plasma_screen.origin.x = 0;
  plasma_screen.origin.y = 0;
  incendie.win = bunny_start(incendie.size.x, incendie.size.y - 100, false, "Incendie");
  incendie.px = bunny_new_pixelarray(incendie.size.x, incendie.size.y);
  plasma_screen.win = bunny_start(plasma_screen.size.x, plasma_screen.size.y, false, "Plasma");
  plasma_screen.px = bunny_new_pixelarray(plasma_screen.size.x, plasma_screen.size.y);
  plasma(&plasma_screen);
  mon_incendie(&incendie);
  bunny_stop(incendie.win);
  bunny_stop(plasma_screen.win);
}
