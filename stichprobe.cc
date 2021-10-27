#include <iostream>
#include <fstream>
#include <cmath>

double mean;
double variance;

void meansum(){
  std::ifstream fin("datensumme.txt");
  double a;
  for (int N=1; N<235; N++) {
    fin >> a ;
    mean += a;
  }
  fin.close();
  mean=mean/234;
  std::cout << "mean = " << mean << std::endl;
}

void var(double mean){
  std::ifstream fin("datensumme.txt");
  double a;
  for (int N=1; N<235; N++) {
    fin >> a ;
    variance += pow((a-mean),2);
  }
  fin.close();
  variance=variance/234;
  std::cout << "variance = " << variance << std::endl;
}

void dev(double variance){
  double deviation;
  deviation = sqrt(variance);
  std::cout << "standard deviation = " << deviation << std::endl;
}

int main(){
  meansum();
  var(mean);
  dev(variance);
}