/*
#include <cmath>
#include <fstream>
#include <iostream>

double mean;
double variance;
std::ifstream fin("datensumme.txt");
std::ofstream fout_m("mittelwerte.txt");
std::ofstream fout_v("varianzen.txt");


int meansum(){
  std::ifstream fin("datensumme.txt");
  double a;
  for (int N=1; N<9; N++) {
    fin >> a ;
    mean += a;
  }
  fin.close();
  mean=mean/9;
  std::cout << "mean = " << mean << std::endl;
}

int var(double mean){
  std::ifstream fin("datensumme.txt");
  double a;
  for (int N=1; N<9; N++) {
    fin >> a ;
    variance += pow((a-mean),2);
  }
  fin.close();
  variance=variance/9;
  std::cout << "variance = " << variance << std::endl;
}

int dev(double variance){
  double deviation;
  deviation = sqrt(variance);
  std::cout << "standard deviation = " << deviation << std::endl;
}


double mean2(int x) {
  for (int N = 1; N < 235; N++) {

    double a;

    if (N == x) {
      mean = 0;
    }

    fin >> a;
    mean += a;

    if (N == (x + 9)) {
      mean = mean / 9;
      return mean;
    }
  }
}

double var2(int x, double meanv) {

  for (int N = 1; N < 235; N++) {

    double a;

    if (N == x) {
      variance = 0;
    }

    fin >> a;
    variance += pow((a - meanv), 2);

    if (N == (x + 9)) {
      variance = variance / 9;
      return variance;
    }
  }
}

int main() {

  for (int x = 1; x < 234; x = x + 9) {
    fout_m << mean2(x) << std::endl;
    fout_v << var2(x, mean) << std::endl;
  }

  fin.close();
  fout_v.close();
  fout_m.close();

  
    meansum(x);
    var(mean);
    dev(variance);
    
}

*/




#include <iostream>
#include <fstream>
#include <cmath>

double mean;
double variance;

int meansum(){
  std::ifstream fin("datensumme.txt");
  std::ofstream fout_m("mittelwerte.txt");
  double a;
  for (int N=1; N<235; N++) {
    fin >> a ;
    mean += a;
    if (N % 9 == 0){
      mean = mean/9;
      fout_m << mean << std::endl;
      mean = 0;
    }
    else{
      continue;
    }
  }
  fin.close();

}

int var(){
  std::ifstream fin("datensumme.txt");
  std::ifstream fin_m("mittelwerte.txt");
  std::ofstream fout_v("varianzen.txt");
  double a,mean_m;
  fin_m >> mean_m ;
  for (int N=1; N<235; N++) {
    fin >> a ;
    variance += pow((a-mean_m),2);
    if (N % 9 == 0){
      variance = variance/9;
      fout_v << variance << std::endl;
      variance = 0;
      fin_m >> mean_m ;
    }
    else{
      continue;
    }
  }
  fin.close();

}

/*
int dev(double variance){
  double deviation;
  deviation = sqrt(variance);
  std::cout << "standard deviation = " << deviation << std::endl;
}
*/

int mean3(){
  std::ifstream fin_m("mittelwerte.txt");
  std::ifstream fin_v("varianzen.txt");
  double a,b,mean_m,mean_v;
  for (int N=1; N<27; N++){
    fin_m >> a;
    fin_v >> b;
    mean_m += a;
    mean_v +=b;
  }
  fin_m.close();
  fin_v.close();
  mean_m = mean_m/26;
  mean_v = mean_v/26;
  std::cout<<"mean_m: "<<mean_m<<" mean_v: "<<mean_v<<std::endl;
}

double bessel_mean;
double bessel_variance;

int bessel_meansum(){
  std::ifstream fin("datensumme.txt");
  double a;
  for (int N=1; N<235; N++) {
    fin >> a ;
    bessel_mean += a;
  }
  fin.close();
  bessel_mean=bessel_mean/233;
  std::cout << "mean with Bessel's correction = " << bessel_mean << std::endl;
}

int bessel_var(double bessel_mean){
  std::ifstream fin("datensumme.txt");
  double a;
  for (int N=1; N<235; N++) {
    fin >> a ;
    bessel_variance += pow((a-bessel_mean),2);
  }
  fin.close();
  bessel_variance=bessel_variance/233;
  std::cout << "variance with Bessel's correction = " << bessel_variance << std::endl;
}

int bessel_dev(double bessel_variance){
  double bessel_deviation;
  bessel_deviation = sqrt(bessel_variance);
  std::cout << "standard deviation with Bessel's Correction = " << bessel_deviation << std::endl;
}

int main(){
  meansum();
  var();
  //dev(variance);
  mean3();

  bessel_meansum();
  bessel_var(bessel_mean);
  bessel_dev(bessel_variance);
}