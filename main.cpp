#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <ctime>
#include "utility.h"
#include "lattice.h"
#include "ising.h"
#include <stdio.h>

#define BOX_SIZE 100
#define N_CYCLES 3000

using namespace std;

int main()
{
    srand(time(0));
    cout << "generating lattice \n";
    float deltaT =0.1;
    cout << N_CYCLES/20 << endl;

    for (size_t i=1; i<45; i++)
    {
        Lattice lattice (BOX_SIZE, 0., 1, i * deltaT); 
        // if (i==19)
            lattice.setStorageOption(true);
        // else
        //     lattice.setStorageOption(false);
        printf("temp: %f\n", i * deltaT);
        lattice.simulate(N_CYCLES);
        printf("Done\n");
    }
    
    // Lattice lattice (BOX_SIZE, 0., 1, 0.1); 
    // lattice.setStorageOption(true);
    // lattice.simulate(N_CYCLES);
}