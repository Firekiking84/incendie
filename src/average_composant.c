#include		"incendie.h"

void			average_composant(t_average	*var)
{
  int i;

  i = 0;
  while(i < 4)
    {
      var->average_col.argb[i] = (var->average_col.argb[i] + var->px_col.argb[i]) / 2;
      i += 1;
    }
}
