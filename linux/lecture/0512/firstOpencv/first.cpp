#include <opencv2/highgui.hpp>
using namespace::cv;
int main(void)
{
	Mat image(300, 400, CV_8UC1, Scalar(200));
	imshow("영상보기", image);
	waitKey(0);
	return 0;
}
