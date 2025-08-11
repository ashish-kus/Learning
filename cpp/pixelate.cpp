#include <iomanip>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <sstream>

std::string bgrToHex(float b, float g, float r) {
  std::stringstream ss;
  ss << "#" << std::hex << std::setfill('0') << std::setw(2)
     << static_cast<int>(r) << std::setw(2) << static_cast<int>(g)
     << std::setw(2) << static_cast<int>(b);
  return ss.str();
}

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <image_path>" << std::endl;
    return 1;
  }

  std::string imagePath = argv[1];
  cv::Mat img = cv::imread(imagePath);

  if (img.empty()) {
    std::cerr << "Error: Could not read the image!" << std::endl;
    return 1;
  }

  // Resize to speed up processing
  cv::Mat small;
  cv::resize(img, small, cv::Size(200, 200));

  // Flatten the image to 2D
  small = small.reshape(1, small.rows * small.cols);
  small.convertTo(small, CV_32F);

  int K = 8;
  cv::Mat labels, centers;

  cv::kmeans(small, K, labels,
             cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT,
                              10, 1.0),
             3, cv::KMEANS_PP_CENTERS, centers);

  std::cout << "Dominant Colors (in HEX):\n";
  for (int i = 0; i < centers.rows; ++i) {
    float b = centers.at<float>(i, 0);
    float g = centers.at<float>(i, 1);
    float r = centers.at<float>(i, 2);
    std::cout << "Color " << i << ": " << bgrToHex(b, g, r) << "\n";
  }

  return 0;
}
