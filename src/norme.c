/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:39 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: Get the norme between two points
 */

int	norme(int a,
	      int b)
{
    int result;

    if (a > b)
      result = a - b;
    else
      result = b - a;
    return (result);
}
