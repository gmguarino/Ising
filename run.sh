g++ main.cpp utility.cpp ising.cpp lattice.cpp -o main -fopenmp
./main
gnuplot graph_plotter.plot
gnuplot matrix_plotter.plot
rm .data/*.dat