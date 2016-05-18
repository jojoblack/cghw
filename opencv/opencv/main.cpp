#include <opencv2/opencv.hpp>

#define w  200

using namespace cv;
using namespace std;


// extern int mytest1();
// extern int mytest2();
extern vector <vector <Point2f>> GetFontEdgePoints();
extern void DrawFont();
// void MyEllipse(Mat img, double angel){
// 	int thickness = 1;
// 	int lineType = 8;
// 	ellipse(img,
// 			Point(w/2.0,w/2.0),
// 			Size(w/4.0,w/16.0),
// 			angel,
// 			0,
// 			360,
// 			Scalar(255,0,0),
// 			thickness,
// 			lineType);
// }
// void MyFilledCircle(Mat img, Point p){
// 	int thickness = -1;
// 	int lineType = 8;
// 	circle(img,
// 			p,
// 			w/32.0,
// 			Scalar(0,255,0),
// 			thickness,
// 			lineType);
// }
// void MyPolygon(Mat img){
// 	int lineType = 8;
// 	/** 创建一些点 */
// 	Point rook_points[1][20];
// 	rook_points[0][0] = Point( w/4.0, 7*w/8.0 );
// 	rook_points[0][1] = Point( 3*w/4.0, 7*w/8.0 );
// 	rook_points[0][2] = Point( 3*w/4.0, 13*w/16.0 );
// 	rook_points[0][3] = Point( 11*w/16.0, 13*w/16.0 );
// 	rook_points[0][4] = Point( 19*w/32.0, 3*w/8.0 );
// 	rook_points[0][5] = Point( 3*w/4.0, 3*w/8.0 );
// 	rook_points[0][6] = Point( 3*w/4.0, w/8.0 );
// 	rook_points[0][7] = Point( 26*w/40.0, w/8.0 );
// 	rook_points[0][8] = Point( 26*w/40.0, w/4.0 );
// 	rook_points[0][9] = Point( 22*w/40.0, w/4.0 );
// 	rook_points[0][10] = Point( 22*w/40.0, w/8.0 );
// 	rook_points[0][11] = Point( 18*w/40.0, w/8.0 );
// 	rook_points[0][12] = Point( 18*w/40.0, w/4.0 );
// 	rook_points[0][13] = Point( 14*w/40.0, w/4.0 );
// 	rook_points[0][14] = Point( 14*w/40.0, w/8.0 );
// 	rook_points[0][15] = Point( w/4.0, w/8.0 );
// 	rook_points[0][16] = Point( w/4.0, 3*w/8.0 );
// 	rook_points[0][17] = Point( 13*w/32.0, 3*w/8.0 );
// 	rook_points[0][18] = Point( 5*w/16.0, 13*w/16.0 );
// 	rook_points[0][19] = Point( w/4.0, 13*w/16.0) ;

// 	const Point* ppt[1] = { rook_points[0] };
// 	int npt[] = { 20 };

// 	fillPoly( img,
// 		        ppt,
// 			    npt,
// 				1,
// 				Scalar( 255, 255, 255 ),
// 				lineType );
// }
// void MyLine(Mat img, Point p1, Point p2){
// 	int thickness = 1;
// 	int lineType = 8;
// 	line(img,
// 			p1,
// 			p2,
// 			Scalar(0,0,0),
// 			thickness,
// 			lineType);
// }

int main(){
	int choice;
	cout << "1: get font points\n";
	cout << "2: draw existing font\n";
	cout << "choice ?\n";
	cin >> choice;
	cin.clear();
	if (choice==1)
		GetFontEdgePoints();
	else if (choice==2)
		DrawFont();


	// char atom_window[] = "Drawing 1: Atom";
	// char rook_window[] = "Drawing 2: Rook";

	// Mat atom_image = Mat::zeros(w,w,CV_8UC3);
	// Mat rook_image = Mat::zeros(w,w,CV_8UC3);

	// MyEllipse(atom_image,90);
	// MyEllipse(atom_image,0);
	// MyEllipse(atom_image,45);
	// MyEllipse(atom_image,-45);

	// MyFilledCircle(atom_image,Point(w/2,w/2));

	// MyPolygon(rook_image);

	// rectangle(rook_image,
	// 			Point(0,7*w/8.0),
	// 			Point(w,w),
	// 			Scalar(0,255,255),
	// 			-1,
	// 			8);

	// MyLine(rook_image, Point(0,15*w/16), Point(w,15*w/16));
	// MyLine(rook_image, Point(w/4,7*w/8), Point(w/4,w));
	// MyLine(rook_image, Point(w/2,7*w/8), Point(w/2,w));
	// MyLine(rook_image, Point(3*w/4,7*w/8), Point(3*w/4,w));

	// namedWindow(atom_window,WINDOW_NORMAL);
	// imshow(atom_window,atom_image);
	// waitKey();
	// namedWindow(rook_window,WINDOW_NORMAL);
	// imshow(rook_window,rook_image);
	// waitKey();

	//mytest1();
	//mytest2();

	return 0;
}