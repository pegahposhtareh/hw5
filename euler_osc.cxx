/*
Pegah Poshtareh
Homework 5
01.12.2015
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
  // Define initial constants
  double pi = M_PI;         // Value of PI = 3.14159265359
  double tstart = 0.0;      // Starting time = 0.0
  double tend = 20.0 * pi;  // Ending time = 62.8318530718
  double dt = pi / 100.0;    // Time steps = 0.314159265359
  double yfwd[2], ybwd[2], yal[2]; // Define 2D arrays for different solutions
  int Nit = int((tend - tstart)/dt) + 1; // Number of itterations
  double fwd0, fwd1, bwd0, bwd1;  // Temperory variables
  double t = 0;

  // Openning files to write the results
  ofstream euler_fwd("euler_fwd.dat");
  ofstream euler_bwd("euler_rwd.dat");
  ofstream eulaer_anal("eulaer_anal.dat");

  // Define the starting valus
  ybwd[0] = 1; // x(0)
  ybwd[1] = 0; // dx/dt (0)
  yfwd[0] = 1;
  yfwd[1] = 0;
  yal[0] = 1;
  yal[1] = 0;

  //Writing the starting valus in the corresponding files
  euler_fwd 	  << t << "\t" << yfwd[0] << "\t" << yfwd[1] << endl;
  euler_bwd 	  << t << "\t" << ybwd[0] << "\t" << ybwd[1] << endl;
  eulaer_anal 	<< t << "\t" << yal[0]  << "\t" << yal[1]  << endl;

  // Solving the equation via a for loop
  for (int i = 0; i < Nit; i++) {
    t = (i+1)* dt; // Time of printing
    // Forward Euler
    fwd0 = yfwd[0];
    fwd1 = yfwd[1];
    yfwd[0] = fwd0 + dt * fwd1;
    yfwd[1] = fwd1 - dt *fwd0;
    euler_fwd 	<< t << "\t" << yfwd[0] << "\t" << yfwd[1] << endl;

    // Backward Euler
    bwd0 = ybwd[0];
    bwd1 = ybwd[1];
    ybwd[0] = (bwd0 + dt * bwd1) / (1 + dt * dt);
    ybwd[1] = (bwd1 - dt * bwd0) / (1 + dt * dt);
    euler_bwd 	<< t << "\t" << ybwd[0] << "\t" << ybwd[1] << endl;

    // Analitical Euler
    yal[0]=cos(t);
    yal[1]=-sin(t);
    eulaer_anal 	<< t << "\t" << yal[0] << "\t" << yal[1] << endl;

  }
  // Closing the result files
  euler_fwd.close();
  euler_bwd.close();
  euler_anal.close();
  
  return 0;
}
