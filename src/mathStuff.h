#include <iostream>
#include <math.h>

float deg2rad (float deg)
{
    return deg * M_PI / 180.;
}

float rad2deg (float rad)
{
    return rad * 180. / M_PI;
}
