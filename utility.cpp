#include "utility.h"

using namespace std;

float rnd::random_float() {return (float) drand48();}
double rnd::random_double() {return drand48();}
int rnd::random_int(int low, int high){return (int)((high - low) * drand48() + low);}

void io::print(char* message) {cout << message << endl;}

int mth::modulo_add_bit(int x, int y){return (x + y) % 2;}

bool in_range(int x, int low, int high)
{
    if ((x >= low) && (x < high))
    {
        return true;
    }
    else
    {
        return false;
    }
}