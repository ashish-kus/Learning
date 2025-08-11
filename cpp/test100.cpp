#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <image_path>\n";
    return 1;
  }

  std::string image_path = argv[1];

  // Load the original image
  cv::Mat image = cv::imread(image_path);
  if (image.empty()) {
    std::cerr << "Error: Could not load image at " << image_path << "\n";
    return 1;
  }

  // Resize the image to 100x100
  cv::Mat resized_image;
  cv::resize(image, resized_image, cv::Size(100, 100), 0, 0, cv::INTER_AREA);

  // Save the resized image
  cv::imwrite("rescaled.png", resized_image);

  std::cout << "Image resized to 100x100 and saved as rescaled.png\n";

  return 0;
}
