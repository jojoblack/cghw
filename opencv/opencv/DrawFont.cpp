#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void myLine(Mat & img, int y1, int x1, int y2, int x2){
	assert(x1 <= img.cols && x2 <= img.cols && y1 <= img.rows && y2 <= img.rows);

	//  Later I'll use bresenham Algorithm to draw a line
	//  First I draw a line directly using the line equation
	if (x1 == x2){
		for (int k = min(y1,y2); k != max(y1,y2); k++){
			img.at<uchar>(x1,k) = 255;
		}
	} else if (y1 == y2){
		for (int k = min(x1,x2); k != max(x1,x2); k++){
			img.at<uchar>(k,y1) = 255;
		}
	} else {
		//  draw the line using the line equation
		double k = (1.0*(y2-y1))/(x2-x1);
		if (x2 > x1)
			for (int i = x1; i <= x2; i++){
				int j = y1 + k*(i-x1);
				img.at<uchar>(i,j) = 255;
			}
		else
			for (int i = x1; i >= x2; i--){
				int j = y1 + k*(i-x1);
				img.at<uchar>(i,j) = 255;
			}

		//  draw the line using bresenham algorithm

	}
}

void myDrawStroke(Mat & img, vector <vector <Point2f>>::iterator const point){
	for (auto i = point->begin(); i != point->end()-1; i++){
		myLine(img,i->x,i->y,(i+1)->x,(i+1)->y);
	}
	myLine(img,point->begin()->x,point->begin()->y,(point->end()-1)->x,(point->end()-1)->y);
}

void myDrawFont(Mat & img, vector <vector<Point2f>> & const points){
	for (auto i = points.begin(); i != points.end(); i++){
		myDrawStroke(img,i);
	}
}

void DrawFont(){
	cout << "please input the font file name\n";
	string FontFile;
	cin >> FontFile;
	cin.clear();

	ifstream infile(FontFile);
	if (!infile){
		cout << "failed to open " << FontFile << endl;
		exit(-1);
	}

	vector <vector <Point2f>> points;
	int W,H;
	infile >> W >> H;
	cout << "read from file " << FontFile << endl;
	cout << "W " << W << " H " << H << endl;
	string part;
	while(1){
		infile >> part;
		cout << "part " << part << endl;
		if (part == "part"){
			points.push_back(vector <Point2f>());
		} else if (part == "EOF"){
			infile.close();
			break;
		} else {
			stringstream ss;
			int x,y;
			ss << part;
			ss >> x;
			ss.clear();
			infile >> part;
			ss << part;
			ss >> y;
			cout << "x " << x << " y " << y << endl;
			points[points.size()-1].push_back(Point2f(x,y));
		}
	}

	Mat img = Mat::zeros(H,W,CV_8UC1);
	// img.zeros(H,W,CV_8UC1);  This kind of opration causes problem
	// img.at<uchar>(50,50) = 255;  //  This shows how to access and change an element in a Mat object
	myDrawFont(img,points);
	namedWindow("draw font",WINDOW_NORMAL);
	imshow("draw font",img);
	waitKey();

}
