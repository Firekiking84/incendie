/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:35 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: get_ratio
 */

float		get_ratio(int a,
			  int b,
			  int x)
{
    float	result;
    int		c;

    c = 0;
    if (a > b)
      {
        c = a;
        a = b;
        b = c;
        c = -1;
      }
    result = (float)(x - a) / (b - a);
    if (c == -1)
        result -= 1;
    return (result);
}
