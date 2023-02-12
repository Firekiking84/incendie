#include		"incendie.h"

static void		gradient(unsigned int				*palette,
				 t_plasma_color				*col,
				 int					*i,
				 unsigned char				*edit_composant)
{
  int			max;

  max = *i + 21;
  while (*i < max)
    {
      *edit_composant += col->step;
      palette[*i] = mk_color(col->r, col->g, col->b, 1);
      *i += 1;
    }
}

void			last_col(unsigned int				*palette,
				 int					*i)
{
  while (*i < 129)
    {
      palette[*i] = mk_color(255, 0, 0, 1);
      *i += 1;
    }
}
 
void			fill_palette_plasma(unsigned int		*palette)
{
  t_plasma_color	color;
  int			step;
  int			i;

  color.step = 12;
  i = 0;
  color.r = 0;
  color.g = 0;
  color.b = 0;
  gradient(palette, &color, &i, &color.g);
  color.step *= -1;
  gradient(palette, &color, &i, &color.r);
  color.step *= -1;
  gradient(palette, &color, &i, &color.b);
  color.step *= -1;
  gradient(palette, &color, &i, &color.g);
  color.step *= -1;
  gradient(palette, &color, &i, &color.r);
  color.step *= -1;
  gradient(palette, &color, &i, &color.b);
  last_col(palette, &i);
}
