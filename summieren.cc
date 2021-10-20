#include <iostream>
#include <fstream>

int main() {
  std::ifstream fin("daten.txt");
  double summand_1;
  double summand_2;
  while (fin >> summand_1 >> summand_2){
    double summe;
    summe = summand_1 + summand_2;
    std::ofstream fout("summe_daten.txt");
    fout << summe << std::endl;
    fout.close();
    std::cout << summe << std::endl;
  }
  //std::cout << summand_1 << summand_2 << summe << std::endl;
  fin.close();
}