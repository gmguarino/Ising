set terminal jpeg


set title "Magnetisation"
set xlabel "Magnetisation (n. of spins)"
set ylabel "Temperature (1/k_B J)"
set output './images/Graphs/Magnetisation.jpeg'

plot "./data/magnetisation.dat" lt 8 title "Magnetisation"

set terminal jpeg

set title "Energy"
set xlabel "Energy"
set ylabel "Temperature (1/k_B J)"
set output './images/Graphs/Energy.jpeg'

plot "./data/energy.dat" lt 7 title "Energy"