#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void myLine(Mat & img, int x1, int y1, int x2, int y2){
	assert(x1 <= img.cols && x2 <= img.cols && y1 <= img.rows && y2 <= img.rows);

	// cout << "debugger x1 " << x1 << " y1 " << y1 << " x2 " << x2 << " y2 " << y2 << endl;

	//  Later I'll use bresenham Algorithm to draw a line
	//  First I draw a line directly using the line equation
	if (x1 == x2){
		for (int k = min(y1,y2); k != max(y1,y2); k++){
			img.at<uchar>(k,x1) = 255;
		}
	} else if (y1 == y2){
		for (int k = min(x1,x2); k != max(x1,x2); k++){
			img.at<uchar>(y1,k) = 255;
		}
	} else {
		//  draw the line using the line equation
		double k = (1.0*(y2-y1))/(x2-x1);

		// cout << "debugger k " << k << endl;

		if (x2 > x1)
			for (int i = x1; i <= x2; i++){
				int j = y1 + k*(i-x1);
				img.at<uchar>(j,i) = 255;
			}
		else
			for (int i = x1; i >= x2; i--){
				int j = y1 + k*(i-x1);
				img.at<uchar>(j,i) = 255;
			}
		// namedWindow("debugger",WINDOW_NORMAL);
		// imshow("debugger",img);
		// waitKey();

		//  draw the line using bresenham algorithm
		// double k = (1.0*(y2-y1))/(x2-x1);
		if (k == 1){
			int xs = min(x1,x2);
			int ys = min(y1,y2);
			int xe = max(x1,x2);
			for (int i = xs; i <= xe; i++){
				img.at<uchar>(ys+i-xs,i) = 255;
			}
		} else if (k == -1){
			int xs = min(x1,x2);
			int ys = max(y1,y2);
			int xe = max(x1,x2);
			for (int i = xs; i <= xe; i++){
				img.at<uchar>(ys-i+xs,i) = 255;
			}
		} else if(k<0 && k>-1){
			int x0 = min(x1,x2);
			int y0 = max(y1,y2);
			img.at<uchar>(y0,x0) = 255;
			int xe = max(x1,x2);
			int deltax = xe - x0;
			int deltay = min(y1,y2) - y0;
			int p0 = -2*deltay - deltax;
			int pd,xd,yd;
			while (x0 != xe){
				if (p0 >= 0){
					pd = p0 - 2*(deltax+deltay);
					xd = x0 + 1;
					yd = y0 - 1;
					img.at<uchar>(yd,xd) = 255;

					x0 = xd;
					y0 = yd;
					p0 = pd;
				} else {
					pd = p0 - 2*deltay;
					xd = x0 + 1;
					yd = y0;
					img.at<uchar>(yd,xd) = 255;

					x0 = xd;
					y0 = yd;
					p0 = pd;
				}
			}
		} else if (k>0 && k<1){
			int x0 = min(x1,x2);
			int y0 = min(y1,y2);
			img.at<uchar>(y0,x0) = 255;
			int xe = max(x1,x2);
			int deltax = xe - x0;
			int deltay = max(y1,y2) - y0;
			int p0 = 2*deltay - deltax;
			int pd,xd,yd;
			while (x0 != xe){
				if (p0 >= 0){
					pd = p0 + 2*(deltay-deltax);
					xd = x0 + 1;
					yd = y0 + 1;
					img.at<uchar>(yd,xd) = 255;

					x0 = xd;
					y0 = yd;
					p0 = pd;
				} else {
					pd = p0 + 2*deltay;
					xd = x0 + 1;
					yd = y0;
					img.at<uchar>(yd,xd) = 255;

					x0 = xd;
					y0 = yd;
					p0 = pd;
				}
			}
		} else if (k>1){
			 int y0 = min(y1,y2);
			 int x0 = min(x1,x2);
			 int ye = max(y1,y2);
			 img.at<uchar>(y0,x0) = 255;
			 int deltax = max(x1,x2) - x0;
			 int deltay = ye - y0;
			 int p0 = 2*deltax - deltay;
			 int xd,yd,pd;
			 while (y0 != ye){
			 	if (p0 >= 0){
			 		yd = y0 + 1;
			 		xd = x0 + 1;
			 		pd = p0 + 2*(deltax - deltay);
			 		img.at<uchar>(yd,xd) = 255;

			 		x0 = xd;
			 		y0 = yd;
			 		p0 = pd;
			 	} else {
			 		yd = y0 + 1;
			 		xd = x0;
			 		pd = p0 + 2*deltax;
			 		img.at<uchar>(yd,xd) = 255;

			 		x0 = xd;
			 		y0 = yd;
			 		p0 = pd;
			 	}
			 }
		} else if (k<-1){
			int x0 = min(x1,x2);
			int y0 = max(y1,y2);
			img.at<uchar>(y0,x0) = 255;
			int ye = min(y1,y2);
			int deltax = max(x1,x2) - x0;
			int deltay = ye - max(y1,y2);
			int p0 = -deltay - 2*deltax;
			int xd,yd,pd;
			while (y0 != ye){
				if (p0 < 0){
					pd = p0 - 2*(deltax+deltay);
					xd = x0 + 1;
					yd = y0 - 1;
					img.at<uchar>(yd,xd) = 255;

					x0 = xd;
					y0 = yd;
					p0 = pd;
				} else {
					pd = p0 -2*deltax;
					xd = x0;
					yd = y0 - 1;
					img.at<uchar>(yd,xd) = 255;

					x0 = xd;
					y0 = yd;
					p0 = pd;
				}
			}
		} else {
			fprintf(stderr,"wrong k!\n");
			exit(-2);
		}
		// namedWindow("debugger",WINDOW_NORMAL);
		// imshow("debugger",img);
		// waitKey();
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
	// cout << "read from file " << FontFile << endl;
	// cout << "W " << W << " H " << H << endl;
	string part;
	while(1){
		infile >> part;
		// cout << "part " << part << endl;
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
			// cout << "x " << x << " y " << y << endl;
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
