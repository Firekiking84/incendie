/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:28 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: Apply average composant of color
 */

#include		"incendie.h"

void			average_composant(t_average	*var)
{
  int                   i;

  i = 0;
  while (i < 4)
    {
      var->average_col.argb[i] = (var->average_col.argb[i] + var->px_col.argb[i]) / 2;
      i += 1;
    }
}
