#include <iostream>
#include <math.h>
#include <random>
#include <stdlib.h>

#ifndef UTILITY
#define UTILITY

namespace rnd {
    float random_float();
    double random_double();
    int random_int(int low, int high);
    };

namespace io{
    void print(char* message);
    };

bool in_range(int x, int low, int high);

namespace mth {
    int modulo_add_bit(int x, int y);
}



#endif
