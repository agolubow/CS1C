#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Shape{
public:

	virtual double calcPerimeter()=0;
	virtual double calcArea()=0;

};

#endif