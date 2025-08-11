#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./resize_image <input_image>\n";
    return 1;
  }

  std::string imagePath = argv[1];
  Mat img = imread(imagePath, IMREAD_COLOR);

  if (img.empty()) {
    std::cerr << "Error: Could not read the image.\n";
    return -1;
  }

  Mat resized;
  resize(img, resized, Size(350, 350)); // Force resize to 350x350

  imwrite("out.jpg", resized); // Save the resized image

  std::cout << "Image saved as out.jpg (350x350)\n";
  return 0;
}
