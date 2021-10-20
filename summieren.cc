#include <iostream>
#include <fstream>

int main() {
  //Define Input textfile
  std::ifstream fin("daten.txt"); 
  double summand_1; //first summand
  double summand_2; //second summand 
  //Define Output textfile
  std::ofstream fout("datensumme.txt");
  while (fin >> summand_1 >> summand_2){
    double summe;
    summe = summand_1 + summand_2; //Sum the two values
    fout << summe << std::endl; //Write into Output textfile
  }
  fout.close(); //Close Output textfile
  fin.close(); //Close Input textfile
}