#include "triangle.h"

double Triangle::calcPerimeter(){
	return (sideOne + sideTwo + sideThree);
}

double Triangle::calcArea(){
	double halfP = 0.5*(sideOne + sideTwo + sideThree);
	return (sqrt(halfP*(halfP-sideOne)*(halfP-sideTwo)*(halfP-sideThree)));
}

void Triangle::setSides(double one,double two,double three){
	sideOne = one;
	sideTwo = two;
	sideThree = three;
}

Triangle::Triangle(){
	sideOne = 0;
	sideTwo = 0;
	sideThree = 0;
}