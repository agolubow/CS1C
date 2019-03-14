#include "rectangle.h"

double Rectangle::calcPerimeter(){
	return ((2*width)+(2*height));
}

double Rectangle::calcArea(){
	return (width*height);
}

void Rectangle::setSides(double width,double height){
	this->width = width;
	this->height = height;
}

Rectangle::Rectangle(){
	width = 0;
	height = 0;
}