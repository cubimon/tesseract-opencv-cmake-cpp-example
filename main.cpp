#include <iostream>

#include <tesseract/baseapi.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
  auto tess = new tesseract::TessBaseAPI();
  if (tess->Init(nullptr, "eng")) {
    std::cerr << "couldn't initialize tesseract\n";
    exit(1);
  }
  auto rgbImg = cv::imread("test.png", 1);
  if (!rgbImg.data) {
    std::cerr << "no image data\n";
    exit(2);
  }
  if (rgbImg.type() != CV_8UC3) {
    std::cerr << "expecting RGB image\n";
    exit(3);
  }
  // convert to grayscale
  // cv::Mat grayImg;
  // cv::cvtColor(rgbImg, grayImg, cv::COLOR_BGR2GRAY);
  auto size = rgbImg.size();
  tess->SetImage(static_cast<uint8_t*>(rgbImg.data), size.width, size.height, rgbImg.channels(), rgbImg.step1());
  auto resultText = tess->GetUTF8Text();
  std::cout << "result text:\n" << resultText << "\n";

  tess->End();
  delete[] resultText;
  return 0;
}
