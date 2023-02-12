int	sens_finder(int a,
		    int b)
{
    int result;

    if (a <= b)
        result = 1;
    else if (a > b)
        result = -1;
    return (result);
}
