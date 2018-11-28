#ifndef CIRCLEDETECTION_H
#define CIRCLEDETECTION_H

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
using namespace cv;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

#define MAP_ENLARGEMENT 5
#define M_TO_PIX				MAP_ENLARGEMENT * 10 / 7
#define MARBLE_RADIUS_M	0.5f
#define MARBLE_RADIUS_P	MARBLE_RADIUS_M * M_TO_PIX
#define IMAGE_FOV				1.047f

enum detection_algorithm {CD_HOUGH, CD_SPR};
enum circle_side {LEFT, RIGHT};

struct circleInfo {
	unsigned int	n = 1;
	int						x0, y0;
	float					r, angle, d;
	double				map_x, map_y;
	bool					prevspotted, spotted = true;
	int						isSpotted(vector<circleInfo>& spottedCircles);
	void					update(circleInfo& spottedCircle);
	void					merge(circleInfo& circle);
};

class CircleDetection {
public:

	CircleDetection();
	~CircleDetection();

	vector<circleInfo>	detectCircles(Mat& image, detection_algorithm algo = CD_HOUGH);
	void								findBoundaries(vector<Point>& hull, Point& top, Point& right, Point& bottom, Point& left);
	void								drawCircles(Mat& image, vector<circleInfo>& circles);
	void								calcCirclePositions(vector<circleInfo>& spottedCircles, Mat& image, vector<circleInfo>& circles, Mat& map, double x_robot, double y_robot, double angle_robot);
	void								mergeMarbles(vector<circleInfo>& circles, vector<circleInfo> spottedCircles);
	void								mapMarbles(Mat& map, vector<circleInfo>& circles);

private:
};

#endif // CIRCLEDETECTION_H
