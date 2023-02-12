/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:34 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: fill the palette of color
 */

#include		"incendie.h"

static void		black_to_red(unsigned int	*palette,
				     unsigned char	*r,
				     int		*step,
				     int		*i)
{
  while (*i < 33)
    {
      palette[*i] = mk_color(*r, 0, 0, 1);
      *r += *step;
      if (*r < 100 && *i > 15)
	*r = 255;
      *i += 1;
    }
}

static void		red_to_yellow(unsigned int	*palette,
				      unsigned char	*g,
				      int		*step,
				      int		*i)
{
  while (*i < 65)
    {
      *g += *step;
      if (*g < 100 && *i > 60)
	*g = 255;
      palette[*i] = mk_color(255, *g, 0, 1);
      *i += 1;
    }
}

static void		yellow_to_white(unsigned int	*palette,
					unsigned char	*b,
					int		*step,
					int		*i)
{
  while (*i < 97)
    {
      *b += *step;
      if (*b < 100 && *i > 90)
	*b = 255;
      palette[*i] = mk_color(255, 255, *b, 1);
      *i += 1;
    }
}

static void		white(unsigned int		*palette,
			      int			*i)
{
  while (*i < 129)
    {
      palette[*i] = mk_color(255, 255, 255, 1);
      *i += 1;
    }
}
  
void			fill_palette(unsigned int	*palette)
{
  
  unsigned char		r;
  unsigned char		g;
  unsigned char		b;
  int			step;
  int			i;

  step = 8;
  i = 0;
  r = 0;
  g = 0;
  b = 0;
  black_to_red(palette, &r, &step, &i);
  red_to_yellow(palette, &g, &step, &i);
  yellow_to_white(palette, &b, &step, &i);
  white(palette, &i);
} 
