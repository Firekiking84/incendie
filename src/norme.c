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
