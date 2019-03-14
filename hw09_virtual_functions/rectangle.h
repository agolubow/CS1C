#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "shape.h"

class Rectangle:public Shape {
public:
	Rectangle();
	double calcPerimeter();
	double calcArea();
	void setSides(double,double);

private:
	double width;
	double height;
};

#endif