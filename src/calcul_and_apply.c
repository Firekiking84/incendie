#include		"incendie.h"

void			calcul_and_apply(t_average	*var)
{
  var->npos = (var->pos_i.y * var->width) + var->pos_i.x;
  if (var->npos >= 0 && var->npos < var->limit)
    {
      var->px_col.full = var->tableau[var->npos];
      average_composant(var);
    }
}
