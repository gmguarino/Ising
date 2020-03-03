#include "lattice.h"


Lattice::Lattice()
{
    std::cout << "Generating lattice sites" << std::endl;
    size = 100;
    external_field = 0;
    coupling = 1;
    temperature = 1;
    M = 0;
    n_sites = pow(size, 2);
    for (size_t i = 0; i < n_sites; i++)
    {
            if (rnd::random_double() > 0.5)
            {
                latticeMat.push_back(1);
                M++;
            }
            else
            {
                latticeMat.push_back(-1);
                M--;
            }
    }
    calcEnergy();
}


Lattice::Lattice(int _size)
{
    std::cout << "Generating lattice sites" << std::endl;
    size = _size;
    external_field = 0;
    coupling = 1;
    temperature = 1;
    M = 0;
    n_sites = pow(size, 2);
    for (size_t i = 0; i < n_sites; i++)
    {
            if (rnd::random_double() > 0.5)
            {
                latticeMat.push_back(1);
                M++;
            }
            else
            {
                latticeMat.push_back(-1);
                M--;
            }
    }
    calcEnergy();
}

Lattice::Lattice(int _size, float external_h, float J, float temp)
{
    std::cout << "Generating lattice sites" << std::endl;
    size = _size;
    external_field = external_h;
    coupling = J;
    temperature = temp;
    M = 0;
    n_sites = pow(size, 2);
    for (size_t i = 0; i < n_sites; i++)
    {
        if (rnd::random_double() > 0.5)
        {
            latticeMat.push_back(1);
            M++;
        }
        else
        {
            latticeMat.push_back(-1);
            M--;
        }
    }
    calcEnergy();
}

/*public*/

/*gets*/
int Lattice::getSize(){return size;}
int Lattice::getNSites(){return n_sites;}
intVector Lattice::getLatticeMatrix(){return latticeMat;}
int Lattice::getValueFromCoordinates(int i, int j){return latticeMat[size * i + j];}
int Lattice::getMag(){return M;}
float Lattice::getEnergy(){return E;};

/*sets*/
void Lattice::setStorageOption(bool option){storeMat = option;}

/*prints*/
void Lattice::printLatticeMatrix()
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; i++)
        {
            printf("%d ", latticeMat[i * size + j]);
        }
        printf("\n");
    }
}


/*Changes*/
void Lattice::analyseSite(int row, int col)
{

    int new_row, new_col;
    int deltaM, environmentSpins;
    float contribution;
    float delta_energy, probability_threshold, _switch;
    float k_boltzmann = 1;

    deltaM = -2 * latticeMat[row * size + col];
    environmentSpins = (latticeMat[ising::periodic(row - 1, size) * size + col]
                       + latticeMat[ising::periodic(row + 1, size) * size + col]
                       + latticeMat[row * size + ising::periodic(col - 1, size)]
                       + latticeMat[row * size + ising::periodic(col + 1, size)]);

    environmentSpins *= -2 * latticeMat[row * size + col];
    delta_energy = -coupling * environmentSpins - external_field * deltaM;

    if (delta_energy <= 0 || rnd::random_float() < exp(- delta_energy / (k_boltzmann * temperature)))
        {
            latticeMat[row * size + col] *= -1;
            M += deltaM;
            E += delta_energy;
        }
}

void Lattice::timeStep()
{
    int j_idx, i_idx;
    for (size_t i = 0; i < n_sites; i++)
    {
        i_idx = rnd::random_int(0, size);
        j_idx = rnd::random_int(0, size);
        analyseSite(i_idx,j_idx);
    }
}
void Lattice::simulate(int cycles)
{
    FILE *Mlog, *Elog;
    std::string MatLog;
    int count = 0;   
    // #pragma omp parallel for num_threads(8)
    for (size_t cycle = 0; cycle <= cycles + 1; cycle++)
    {
        Lattice::timeStep();
        count++;
        // if (storeMat == true && (count % 500 == 0) || count == 1)
        // {   
        //     MatLog = "./data/matrix_T_" + std::to_string(temperature) + "_cycle_" + std::to_string(count) + ".dat";
        //     std::ofstream file(MatLog);
        //     for (size_t i=0; i<size; i++)
        //     {
        //         for (size_t j = 0; j < size; j++)
        //         {
        //             file << latticeMat[i* size + j] << " ";
        //         }
        //         file << "\n";
        //     }
        //     file.close();
        // }
        
    }

    calcMag();
    Mlog = fopen("./data/magnetisation.dat", "a+");
    fprintf(Mlog, "%f \t %d\n", temperature, abs(M));
    fclose(Mlog);
    Elog = fopen("./data/energy.dat", "a+");
    fprintf(Elog, "%f \t %f\n", temperature, E);
    fclose(Elog);
    if (storeMat == true)
    {   
        MatLog = "./data/ising_T_" + std::to_string(temperature) + ".dat";
        std::ofstream file(MatLog);
        for (size_t i=0; i<size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                file << latticeMat[i* size + j] << " ";
            }
            file << "\n";
        }
        file.close();
    }
    
}
void Lattice::calcEnergy()
{
    int nn_count = 0;    // nearest neighbour count

   for(int i=0; i<size; i++)
      for(int j=0; j<size; j++)
        {  if(latticeMat[i * size + j]==latticeMat[(i+1)* size + j])
              nn_count++;
           else 
              nn_count--;
           if(latticeMat[i * size + j]==latticeMat[i * size + j + 1])
              nn_count++;
           else
              nn_count--;
        }
    
    E = -coupling*nn_count - external_field*M;
}
void Lattice::calcMag()
{
    M = 0;
    for(int i=0; i<size; i++)
      for(int j=0; j<size; j++)
        {  
            M += latticeMat[i* size + j];
        }
    printf("Mag : %d\n", abs(M));
}

