
#include "file_utils.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <file_path>\n";
    return 1;
  }

  std::string filePath = argv[1];
  replaceZerosWithFives(filePath);
  std::cout << "Replaced all 0s with 5s in the file.\n";

  return 0;
}
