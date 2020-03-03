#include <eigen3/Eigen/Sparse>
#include <eigen3/unsupported/Eigen/SparseExtra>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include <math.h>
#include <omp.h>

#include "utility.h"
#include "ising.h"

#ifndef LATTICE
#define LATTICE

typedef Eigen::SparseMatrix<int> SpMat;
typedef Eigen::Triplet<int> T;
typedef std::vector<int> intVector;

class Lattice
{
    private:
        int size;
        int n_sites;
        float external_field;
        float coupling;
        float temperature;
        float k_boltzman = 1;
        int M = 0;
        float E = 0;
        intVector latticeMat;
        bool storeMat = true;

    public:
        Lattice();
        Lattice(int _size);
        Lattice(int _size, float external_h, float J, float temp);
        
        int getSize();
        int getNSites();
        intVector getLatticeMatrix();
        int getValueFromCoordinates(int i, int j);
        int getMag();
        float getEnergy();

        void setStorageOption(bool option);

        void printLatticeMatrix();
        void calcEnergy();
        void calcMag();
        void analyseSite(int row, int col);
        void timeStep();
        void simulate(int cycles);
};



#endif