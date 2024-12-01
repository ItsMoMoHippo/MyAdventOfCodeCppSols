#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void closeFile(std::ifstream &);

int main() {
  std::ifstream f1("file1.txt");

  if (!f1) {
    std::cerr << "couldnt open files";
    closeFile(f1);
    return -1;
  }

  std::vector<int> v1;
  std::vector<int> v2;
  std::string temp;
  while (std::getline(f1, temp)) {
    v1.push_back(std::stoi(temp.substr(0, 5)));
    v2.push_back(std::stoi(temp.substr(8)));
  }

  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());

  int vecSize = v1.size();
  int disTotal = 0;
  int tempInt;
  for (int i = 0; i < vecSize; i++) {
    tempInt = v1[i] - v2[i];
    tempInt = std::abs(tempInt);
    disTotal += tempInt;
  }

  std::cout << disTotal;

  return 0;
}

void closeFile(std::ifstream &a) {
  if (a) {
    a.close();
  }
}
