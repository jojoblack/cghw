#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void myDraw(Mat & img,const vector <vector<Point2f>> & const points){

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

	Mat img;
	img.zeros(H,W,CV_8UC1);
	img.at<uchar>(50,50) = 255;
	myDraw(img,points);
	namedWindow("draw font",WINDOW_NORMAL);
	imshow("draw font",img);
	waitKey();

}
