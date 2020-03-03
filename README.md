# Ising 
The ising model is used to simulate a system of spins on a squared lattice (in 2D) with nearest neighbour interaction. Such a model can be used to examine the behaviour of ferromagnets as they transition above the Curie temperature <img src="https://render.githubusercontent.com/render/math?math=T_C"> into a disordered phase.

The Ising Hamiltonian has the form:

<img src="https://render.githubusercontent.com/render/math?math=H = -J_{ij} \Sigma_{\{i,j\}} \sigma_i \sigma_j - \mu\Sigma_j h_j \sigma_j">

where J is an interspin coupling constant (set to 1 for simplicity)

## Images
![alt text](images/Graphs/Energy.jpeg "Energy vs Temperature")
![alt text](images/Graphs/Magnetisation.jpeg "Magnetisation vs Temperature")
#### T=1.7
Sub critical behaviour: clear separation of domains.
![alt text](images/MetaStable/ising_T_1.700000.png "T = 1.7")
#### T=2.2
Near-critical behaviour: Merging of the domains.
![alt text](images/MetaStable/ising_T_2.200000.png "T = 2.2")
#### T=3.0
Over critical behaviour: disordered phase, entropy takeover.
![alt text](images/MetaStable/ising_T_3.000000.png "T = 3.0")

### Anti-ferromagnet configuration (Negative coupling term)
When the coupling term J becomes negative it is energetically favourable for spins to anti-allign in an anti-ferromagnetic phase. Different antiferromagnetic domains can be seen separated by domain walls.

![alt text](images/MetaStable/Antiferromagnet.png "Anti-Ferromagnet")
