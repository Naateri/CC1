#include <iostream>
#include <math.h>
#include "point.h"
#include "vector.h"
#include "pointarray.h"
#include "polygon.h"
#include "triangle.h"
Triangle::Triangle(Point A, Point B, Point C){
	this -> instances++;
	Point a[3] = {A, B, C};
	PointArray Array(a, 3);
	this -> array = Array;
	
}

double Triangle::area(){
	double a, b, c, s;
	Point *A = array.get(0);
	Point *B = array.get(1); Point *C = array.get(2);
	Vector AB(A,B);
	Vector AC(A,C);
	Vector BC(B,C);
	a = AB.distancia();
	b = BC.distancia();
	c = AC.distancia();
	s = (a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
	
}
