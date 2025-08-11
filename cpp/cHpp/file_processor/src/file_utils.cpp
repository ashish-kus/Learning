#include "file_utils.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

void replaceZerosWithFives(const std::string &filePath) {
  std::ifstream inFile(filePath);
  if (!inFile.is_open()) {
    std::cerr << "Error: Cannot open file for reading: " << filePath << "\n";
    return;
  }

  std::stringstream buffer;
  buffer << inFile.rdbuf();
  std::string content = buffer.str();
  inFile.close();

  for (char &ch : content) {
    if (ch == '0')
      ch = '5';
  }

  std::ofstream outFile(filePath);
  if (!outFile.is_open()) {
    std::cerr << "Error: Cannot open file for writing: " << filePath << "\n";
    return;
  }

  outFile << content;
  outFile.close();
}
