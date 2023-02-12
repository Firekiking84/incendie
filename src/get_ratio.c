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
