
#include <iostream>
#include<opencv2/opencv.hpp>


using namespace std;
using namespace cv;


void img_rotate(Mat img)
{

	Mat img_temp, rez;
	int flag = 0;
	double a, b;
	cout << "Enter the angle to rotate  :";
	cin >> a;
	cout << "Choose option:" << endl;
	cout << "1: Clockwise 2: Anticlockwise  :";
	cin >> b;

	if (b == 1)
	{
		a = 360.00 - a;
	}
	else if (b != 1 && b != 2)
	{
		cout << "PLEASE ENTER THE VALID OPTION ;]";
		flag = 1;
	}
	if (flag == 0)
	{
		Point2f center(img.cols / 2.0F, img.rows / 2.0F);
		Mat rot = getRotationMatrix2D(center, a, 1.0);
		Rect2f corner = RotatedRect(Point2f(), img.size(), a).boundingRect2f();
		rot.at<double>(0, 2) += corner.width / 2.0 - img.cols / 2.0;
		rot.at<double>(1, 2) += corner.height / 2.0 - img.rows / 2.0;
		warpAffine(img, img_temp, rot, corner.size());
		namedWindow("GOD OF THUNDER", WINDOW_NORMAL);
		resizeWindow("GOD OF THUNDER", 700, 700);
		imshow("GOD OF THUNDER", img_temp);
		waitKey(0);
		destroyWindow("GOD OF THUNDER");
	}
}
int main()
{
	Mat img = imread("THUNDER.jpg", IMREAD_COLOR);
	if (img.empty())
	{
		cout << " ERROR!";
		cin.get();
		return -1;
	}

	img_rotate(img);
}