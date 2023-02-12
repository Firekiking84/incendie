#include		"incendie.h"
#include		<lapin.h>
#include		<stdlib.h>
#include		<time.h>  

static void		limit(t_bunny_position		*pos,
			      t_window			*win)
{
  if (pos[0].x < 0)
    pos[0].x = 0;
  if (pos[1].x < 0)
    pos[1].x = 0;
  if (pos[0].y < 0)
    pos[0].y = 0;
  if (pos[1].y < 0)
    pos[1].y = 0;
  if (pos[0].x >= win->size.x)
    pos[0].x = win->size.x - 1;
  if (pos[1].x >= win->size.x)
    pos[1].x = win->size.x - 1;
  if (pos[0].y >= win->size.y)
    pos[0].y = win->size.y - 1;
  if (pos[1].y >= win->size.y)
    pos[1].y = win->size.y - 1;
}

static void		get_pos(t_bunny_position	*pos,
				t_window		*win,
				int			*i)
{
  if (*i == 0)
    {
      pos[0].x = rand() % win->size.x;
      pos[0].y = win->size.y;
    }
  else
    {
      if ((rand() % 2) == 0)
	pos[1].x = pos[0].x - (rand() % 25);
      else
	pos[1].x = pos[0].x + (rand() % 25);
      pos[1].y = pos[0].y - ((rand() % 100) + (win->size.y * 0.05));
    }
  limit(pos, win);
}
  

static void		draw_body(t_window		*win,
				  unsigned int		*palette)
{
  int			n_point;
  int			start_point;
  int			i;
  t_bunny_position	pos[2];

  n_point = rand() % 4;
  start_point = rand() % win->size.x;
  i = 0;
  while (i < n_point || i == 0)
    {
      get_pos(&pos[0], win, &i);
      if (i > 1)
	{
	  def_shape(&pos[0], win, palette);
	  pos[0].x = pos[1].x;
	  pos[0].y = pos[1].y;
	}
      i += 1;
    }
}
  

void			def_fire_body(t_window		*win,
				      unsigned int	*palette)
{
  int			n_body;
  int			i;
  
  srand(time(NULL));
  n_body = rand() % win->size.x;
  if (n_body == 0)
    n_body += 1;
  i = 0;
  while (i < n_body)
    {
      draw_body(win, palette);
      i += 1;
    }
}
      
      
