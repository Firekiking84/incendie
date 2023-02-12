/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:37 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: init layer values of the shape body
 */

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
