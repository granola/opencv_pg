#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
  cv::Mat	src, dst1, dst2, dst3, dst4;
  src = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);

  // 2値化処理
  // * 2値化閾値 = 140, 変換後の最大値 = 255
  cv::threshold(src, dst1, 140, 255, cv::THRESH_BINARY);

  // 2値化処理（判別分析2値化法（大津の方法））
  // * 最適な閾値を自動的に算出する
  cv::threshold(src, dst2, 0, 255, cv::THRESH_OTSU);

  // 膨張処理（最大値フィルタ）
  cv::dilate(dst2, dst3, cv::Mat());

  // 収縮処理（最小値フィルタ）
  cv::erode(dst2, dst4, cv::Mat());

  // cv::imshow("原画像", src);
  // cv::imshow("2値化処理", dst1);
  cv::imshow("2値化処理（大津の方法）", dst2);
  // cv::imshow("膨張処理", dst3);
  // cv::imshow("収縮処理", dst4);

  cv::waitKey();

  return 0;
}
