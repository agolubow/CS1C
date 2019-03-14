#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "shape.h"

class Triangle:public Shape{
public:
	Triangle();
	double calcPerimeter();
	double calcArea();
	void setSides(double,double,double);

private:
	double sideOne;
	double sideTwo;
	double sideThree;
};

#endif