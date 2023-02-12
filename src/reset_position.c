/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:40 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: Reset the position of the cursor
 */

#include		"incendie.h"

/*Sens représente le "profil" de reset. Il permet de revenir au point de
 *départ selon les mouvements fait par la fonction précédente.
 *Sens représente :
 *	0 pour behind
 *	1 pour front
 *	2 pour below
 *	3 pour top
 */

void			reset_position(int		i,
				       t_average	*var,
				       int		sens)
{
  if (sens == 0)
    move_cursor(var, i, 0);
  else if (sens == 1)
    move_cursor(var, -i, 0);
  else if (sens == 2)
    move_cursor(var, -i, i);
  else if (sens == 3)
    move_cursor(var, -i, -i);
}
