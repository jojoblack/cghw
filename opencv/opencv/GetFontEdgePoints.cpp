#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void onMouse2(int event, int x, int y, int flags, void * param){
	vector <vector <Point2f>> * points = reinterpret_cast < vector<vector<Point2f>> * > (param);
	if (points->size()==0){
		points->push_back(vector<Point2f>());
	}
	switch (event){
		case CV_EVENT_LBUTTONDOWN:
			(points->end()-1)->push_back(Point2f(x,y));
			cout << "x = " << x << ", y = " << y << endl;
			break;
		case CV_EVENT_RBUTTONDOWN:
			points->push_back(vector<Point2f>());
			cout << "added a new part in the font\n";
			break;
		default: break;
	}
}

void SaveFont(vector< vector<Point2f> >&points, int W, int H){
	string SaveFileName;
	cout << "please input the name of the file to save the font in:\n";
	cin >> SaveFileName;
	cin.clear();

	fstream outFile;
	outFile.open(SaveFileName,ios::out);
	if (!outFile){
		cout << "failed to open " << SaveFileName << endl;
		exit(-1);
	}

	outFile << W << " " << H << endl;

	for (auto i = points.begin(); i != points.end(); i++){
		outFile << "part" << endl;
		for (auto j = i->begin(); j != i->end(); j++){
			outFile << j->x << " " << j->y << endl;
		}
	}
	outFile << "EOF";

	outFile.close();
	cout << "successfully saved font file\n";
}

vector <vector <Point2f>> GetFontEdgePoints(){
	string FontImgFile;
	cout << "please input the Font image:\n";
	cin >> FontImgFile;
	cin.clear();

	Mat FontImg = imread(FontImgFile.c_str());
	vector <vector<Point2f>> points;
	if (FontImg.empty()){
		fprintf(stderr,"can't open image file %s",FontImgFile.c_str());
		return points;
	}

	namedWindow("Font Image",WINDOW_NORMAL);
	setMouseCallback("Font Image",onMouse2,(void*) &points);
	imshow("Font Image",FontImg);
	cout << "Use left button to get a point on the edge" << endl;
	cout << "Use right button to start capturing a new stroke" << endl;
	cout << "The first part:\n";
	waitKey();

	if (points[points.size()-1].size()==0){
		points.pop_back();
	}

	SaveFont(points,FontImg.cols,FontImg.rows);

	return points;
}