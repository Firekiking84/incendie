#include	<stdlib.h>

void		init_layer_value(int		*len,
				 int		*i,
				 int		*rand_value,
				 int		range)
{
  *len = rand() % range;
  if (*len < 10 && range > 20)
    *len = 10;
  *i = 0;
  *rand_value = 0;
}
