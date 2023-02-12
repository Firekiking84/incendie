/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:35 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: get value from a ratio
 */

int	get_value(int	a,
		  int	b,
		  float ratio)
{
    int x;

    x = ratio * (b - a) + a;
    return (x);
}


