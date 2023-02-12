#ifndef			_INCENDIE_

#define			_INCENDIE_

#include		"window.h"
#include		"line_properties.h"
#include		"average.h"
#include		"color.h"

void			incendie(t_window			*win);
void			fill_palette(unsigned int		*palette);
unsigned int		mk_color(unsigned char			r,
				 unsigned char			g,
				 unsigned char			b,
				 unsigned char			a);
void			diagonale_line(struct line_properties	*draw,
				       t_window			*info);
float			get_ratio(int				a,
				  int				b,
				  int				x);
int			get_value(int				a,
				  int				b,
				  float				ratio);
int			norme(int				a,
			      int				b);
int			sens_finder(int				a,
				    int				b);
void			set_line(struct line_properties		*draw,
				 t_window			*info);
void			set_pixel(t_bunny_pixelarray		*px,
				  t_bunny_position		*pos,
				  unsigned int			color);
float			val_abs_f(float				x);
void			def_lower_line(unsigned int		*palette,
				       t_window			*win);
void			init_pixelarray(t_window		*win,
					unsigned int		color);
unsigned int		average_color(int			i,
				      int			limit,
				      t_bunny_pixelarray	*px,
				      int			neighbour);
void			move_cursor(t_average			*var,
				    int				add_x,
				    int				add_y);
void			calcul_and_apply(t_average		*var);
void			average_composant(t_average		*var);
void			reset_position(int			i,
				       t_average		*var,
				       int			sens);
void			def_fire(unsigned int			*palette,
				 t_window			*win);
void			def_fire_body(t_window			*win,
				      unsigned int		*palette);
void			def_shape(t_bunny_position		*pos,
				  t_window			*win,
				  unsigned int			*palette);
void			draw_shapes(t_bunny_position		pixel_pos,
				    t_window			*win,
				    unsigned int		*palette);
void			init_layer_value(int			*len,
					 int			*i,
					 int			*rand_value,
					 int			range);
void			mon_incendie(t_window			*win);
void			diagonale_management(t_bunny_position	*pos,
					     t_window		*win,
					     unsigned int	*palette);
void			def_smoke(t_window			*win);
void			plasma(t_window				*win);
void			fill_palette_plasma(unsigned int	*palette);

#endif
