do for [id=1:44]{
T = 0.1 * id
#T = 0.1
cycle = id #* 500
set term pngcairo 
file_insert = sprintf("%f.dat", T)
#file_insert = sprintf("%f_cycle_%d.dat", T, cycle)
set print "-"

print 'data/ising_T_'.file_insert

unset key
unset xtics
unset ytics
# Color runs from white to green
set palette greyscale
set cbrange [-1:1]
set cblabel "Score"
unset cbtics
unset colorbox


#set output './images/ising_T_'.sprintf("%f_cycle_%d.png", T, cycle)
set output './images/MetaStable/ising_T_'.sprintf("%f.png", T)

set view map
splot 'data/ising_T_'.file_insert matrix with image
#splot 'data/matrix.dat' matrix with image
}
