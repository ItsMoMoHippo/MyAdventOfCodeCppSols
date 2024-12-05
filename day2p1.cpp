#include <array>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  // opening file
  std::ifstream fi("day2in.txt");
  if (!fi) {
    std::cerr << "!file";
    return -1;
  }

  // line parsing
  int ln = 1;
  int total = 0;
  std::string line; // Line input

  std::array<std::vector<char> *, 9> av; // array of vec
  for (auto &vp : av) {
    vp = new std::vector<char>();
  }

  std::vector<int> nv; // number vec
  int temp = 0;
  while (std::getline(fi, line)) {
    std::cout << "doing line " << ln << '\n';
    int ap = 0; // number counter
    // spliiting up line
    for (char c : line) {
      if (c != ' ') {
        av[ap]->push_back(c);
      } else {
        ap++;
      }
    }

    // converting chars to nums
    for (auto &chars : av) { // for stringified nums in overall vec
      int temp = 0;
      for (char digit : *chars) { // for all the chars in the "string"
        temp = (temp * 10) + (digit - '0');
      }
      if (temp == 0) {
        continue;
      }
      nv.push_back(temp); // add nums to a int vector
    }

    // validation
    bool val = true;
    bool incr = false, decr = false;
    for (int i = 1; i < nv.size(); i++) {
      int dif = nv[i] - nv[i - 1];
      if (std::abs(std::abs(dif) - 2) > 1) {
        val = false;
      }
      if (dif > 0) {
        if (decr) {
          val = false;
          break;
        }
        incr = true;
      }
      if (dif < 0) {
        if (incr) {
          val = false;
          break;
        }
        decr = true;
      }
    }
    if (val) {
      total++;
    }

    // reset for next pass
    for (auto &chars : av) {
      chars->clear();
    }
    nv.clear();
    std::cout << "parsed " << ln << " line\n";
    ln++;
  }

  for (auto &vecs : av) {
    delete vecs;
  }

  std::cout << total;
  return 0;
}
