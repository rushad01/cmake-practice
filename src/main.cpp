#include <iostream>
#include <vector>

int main() {
  std::cout << "Cmake Practice";
  std::vector<int> ivec{1, 2, 3, 4, 6};
  for (auto &i : ivec) {
    std::cout << i << " ";
  }
  return 0;
}