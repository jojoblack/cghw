#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>

using namespace cv;

void onMouse1(int event, int x, int y, int flags, void* param){
	switch (event){
		case CV_EVENT_LBUTTONDOWN:   // when left button clicked
			std::cout << "current point: " << x << ", " << y << std::endl;
		break;
	}
}

int mytest1(){
	std::cout << "in test 1\n";

	string pic_name;
	std::cout << "input the image name:\n";
	std::cin >> pic_name;
	std::cin.clear();
	Mat img = imread(pic_name.c_str());

	if (img.empty()){
		fprintf(stderr,"can't open image file %s\n",pic_name.c_str());
		return -1;
	}

	namedWindow("my window",WINDOW_NORMAL);
	setMouseCallback("my window",onMouse1);
	imshow("my window",img);
	waitKey();

	std::cout << "test 1 over\n";
	return 0;
}
int mytest2(){
	std::cout << "in test 2\n";

	string pic_name;
	std::cout << "input the image name:\n";
	std::cin >> pic_name;
	std::cin.clear();
	Mat img = imread(pic_name.c_str());

	if (img.empty()){
		fprintf(stderr,"can't open image file %s\n",pic_name.c_str());
		return -1;
	}

	namedWindow("test image",WINDOW_NORMAL);
	imshow("test image 2",img);



	std::cout << "test 2 over\n";
	return 0;
}