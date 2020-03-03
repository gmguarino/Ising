#include "ising.h"
#include "utility.h"

int ising::periodic(int index, int limit)
{
    if (index >= limit){index -= limit;}
    if (index < 0){index += limit;}
    return index;
}

int ising::open(int index, int limit)
{
    if (index >= limit || index < 0)
    {index = rnd::random_int(0, limit);}
    return index;
}