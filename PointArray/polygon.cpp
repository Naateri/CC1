#include<iostream>
#include "point.h"
#include "pointarray.h"
#include "polygon.h"
using namespace std;
Polygon::Polygon(){
	Point list[0];
	PointArray PA(list, 0);
	this -> array = PA;
	this->instances = 0;
}
/*const double Polygon::area() = 0;{ 
	return 0;
}*/
Polygon::Polygon(Polygon &p){
	int i;
	this->instances = p.instances;
	PointArray A(p.array);
	this->array =A; 
}
Polygon::Polygon(Point Pls[], int i){
	int j;
	this->instances = i;
	PointArray PLS(Pls, i);
	this->array = PLS;
}
int Polygon::getNumPolygons(){
	return instances;
}
int Polygon::getNumSides(){
	return array.getSize() -1;
}
Point * Polygon::getPoints(){
	//return *array; FIX
	;
}
