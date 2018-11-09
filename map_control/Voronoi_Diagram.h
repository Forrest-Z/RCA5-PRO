#ifndef VORONI_DIAGRAM_H
#define VORONI_DIAGRAM_H

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/ximgproc.hpp"

#include "Map.h"

using namespace std;
using namespace cv;

class Voronoi_Diagram
{
public:
    Voronoi_Diagram();
    Voronoi_Diagram(Mat &src);

    void print_map(Mat &img, string s);

    Mat get_brushfire_grid();
    Mat get_rooms_map();
    vector<Point> get_voronoi_points();

private:
    Mat brushfire_grid;
    Mat voronoi_diagram_img;
    Mat rooms_map;
    vector<Point> voronoi_points;

    void watershed_algorithm(Mat &src);
};

#endif // VORONI_DIAGRAM_H
