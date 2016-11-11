#include<iostream>
#include "point.h"
#include "pointarray.h"
#include "vector.h"
#include "vectorarray.h"
#include "polygon.h"
#include "rectangle.h"
#include "triangle.h"
using namespace std;

int main () {
	Triangle triangle;
	Polygon* MyTria = &triangle;
	Rectangle *rect; //ejercicio 3: cast
	Polygon* MyRect = rect;
	rect = dynamic_cast<Rectangle*>(MyRect);
	//rect = dynamic_cast<Triangle*>(MyRect);
	Rectangle* rekt = rect;
	rect = dynamic_cast<Rectangle*>(MyTria);
	if (rect == NULL){
		cout << "It is not a triangle" << endl;
	}
	
	
	
	return 0;
}
