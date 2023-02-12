/*
 * EFRITS
 * project:     incendie
 * created on:  2023-02-13 - 00:41 +0100
 * 1st author:  keryan.houssin - keryan.houssin
 * description: Absolute value of float
 */

float val_abs_f(float x)
{
    if (x < 0) {
        x *= -1;
    }
    return (x);
}
