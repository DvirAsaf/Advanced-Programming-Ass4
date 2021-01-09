
#ifndef MINCIRCLE_H_
#define MINCIRCLE_H_

#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "anomaly_detection_util.h"

using namespace std;

class Circle{
public:
	Point center;
	float radius;
	Circle(){};
	Circle(Point c,float r):center(c),radius(r){}
};
// --------------------------------------

float distance(const Point& a, const Point& b);

Circle get_circle_by_two_points(const Point& p1, const Point& p2);

//Point circumcenter(Point b, Point c);

Circle get_circle_by_three_points(const Point& p1, const Point& p2,const Point& p3);

Circle min_possible_circle(vector<Point>& point);

Circle welzl_algorithem(vector<Point>& p1, vector<Point> p2, int n);

Circle findMinCircle(Point** points,size_t size);

bool is_in_circle(const Circle& c, const Point& p);

#endif /* MINCIRCLE_H_ */
