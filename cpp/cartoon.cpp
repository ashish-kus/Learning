#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./cartoon <image_path>\n";
    return 1;
  }

  std::string imagePath = argv[1];
  Mat img = imread(imagePath, IMREAD_COLOR);

  // Step 1: Load Image
  if (img.empty()) {
    std::cerr << "Image not found!\n";
    return -1;
  }

  // Step 2: Apply bilateral filter to smooth
  Mat color;
  bilateralFilter(img, color, 9, 75, 75); // Can repeat for stronger effect

  // Step 3: Convert to grayscale
  Mat gray;
  cvtColor(img, gray, COLOR_BGR2GRAY);

  // Step 4: Median blur to reduce noise
  Mat blurred;
  medianBlur(gray, blurred, 7);

  // Step 5: Detect edges using adaptive threshold
  Mat edges;
  adaptiveThreshold(blurred, edges, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY,
                    9, 2);

  // Step 6: Convert edges to 3-channel image
  Mat edgesColor;
  cvtColor(edges, edgesColor, COLOR_GRAY2BGR);

  // Step 7: Bitwise AND to combine
  Mat cartoon;
  bitwise_and(color, edgesColor, cartoon);

  // Show and save
  imshow("Cartoonified", cartoon);
  imwrite("cartoonified.jpg", cartoon);
  waitKey(0);
  return 0;
}
