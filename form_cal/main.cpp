#include<iostream>
#include<opencv2\opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat src = imread("coin.png", 0);
	Mat dist;
	Mat result1;
	Mat	result2;
	Mat result3;
	Mat result4;
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	threshold(src, dist, 100, 255, THRESH_OTSU);
	morphologyEx(dist, result1, MORPH_ERODE,element);
	morphologyEx(dist, result2, MORPH_DILATE, element);
	morphologyEx(dist, result3, MORPH_OPEN, element);
	morphologyEx(dist, result4, MORPH_CLOSE, element);
	imshow("dist", dist);
	imshow("src", src);
	imshow("erode", result1);
	imshow("dilate", result2);
	imshow("open", result3);
	imshow("close", result4);
	waitKey(0);
}