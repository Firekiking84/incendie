/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:40 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: Find the sens of a vecteur
 */

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
