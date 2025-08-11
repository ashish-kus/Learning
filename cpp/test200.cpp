#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./resize <image_path>\n";
    return 1;
  }

  std::string imagePath = argv[1];
  Mat img = imread(imagePath, IMREAD_COLOR);

  if (img.empty()) {
    std::cerr << "Image not found!\n";
    return -1;
  }

  // Resize to 200 x 2000 pixels
  Mat resized;
  resize(img, resized, Size(200, 2000), 0, 0,
         INTER_NEAREST); // INTER_NEAREST gives pixelated effect

  // Save and show result
  imwrite("resized.jpg", resized);
  imshow("Resized Image", resized);
  waitKey(0);

  return 0;
}
