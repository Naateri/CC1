#include<iostream>
#include "point.h"
#include "pointarray.h"
#include "polygon.h"
using namespace std;
Polygon::Polygon(){
	this->instances = 0;
	this->array = PointArray array(); //FIX
}
const double Polygon::area() = 0;/*{ FIX
	return 0;
}*/
int Polygon::getNumPolygons(){
	return instances;
}
int Polygon::getNumSides(){
	return array->getSize();
}
Point * Polygon::getPoints(){
	;
}
