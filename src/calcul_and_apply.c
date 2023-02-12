/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:28 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: Calcul the average color and apply it
 */

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
