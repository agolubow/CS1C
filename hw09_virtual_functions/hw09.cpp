#include "rectangle.h"
#include "triangle.h"

void printPerimeter(Shape&);
void printArea(Shape&);

int main(){

	Rectangle rectangle;
	Triangle triangle;

	rectangle.setSides(7,5);
	cout << "---Rectangle---"<<endl<<endl;
	printPerimeter(rectangle);
	printArea(rectangle);

	triangle.setSides(3,4,5);
	cout << "---Triangle---"<<endl<<endl;
	printPerimeter(triangle);
	printArea(triangle);

	return 0;
}

void printPerimeter(Shape& shape){
	cout <<"Perimeter: "<<shape.calcPerimeter() << endl;
}

void printArea(Shape& shape){
	cout <<"Area: "<<shape.calcArea() << endl<<endl;
}
