#include "point.h"
#include "pointarray.h"
#include "polygon.h"
#include "rectangle.h"
#include<iostream>
#include<stdlib.h>

Rectangle::Rectangle(Point Low, Point High){
	this->instances++;
	Point list[2] = {Low, High};
	PointArray Rekt(list, 2);
	this->array = Rekt;
}

Rectangle::Rectangle(int a, int b, int c, int d){
	Point Low(a, b);
	Point High(c, d);
	Point list[2] = {Low, High};
	PointArray Rekt(list, 2);
	this->array = Rekt;
	this->instances = 2;
}
double Rectangle::area(){
	int height, width;
	int x1, x2, y1, y2;
	Point *Low, *High;
	Low = array.get(0);
	High = array.get(1);
	x1 = Low->getx();
	x2 = High->getx();
	y1 = Low->getx();
	y2 = High->getx();
	height =  y2-y1;
	width = x2-x1;
	return height*width;
}
