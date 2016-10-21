#include<iostream>
#include "point.h"

using namespace std;
Point::Point(){
		x = 0; y = 0;
	}
Point::Point(int nx, int ny){
		x = nx; y = ny;
	}
Point::Point(Point &o){
	x = o.x; y = o.y;
	//setx(o.getx());
	//sety(o.gety());
}
void Point::setx(int nx){
		x = nx;
	}
void Point::sety(int ny){
		y = ny;
	}
int Point::getx(){
		return x;
	}
int Point::gety(){
		return y;
	}
void Point::printPoint(){
		cout << "(" << x << "," << y << ")" << endl;
	}
void Point::modifyPoint(int nx, int ny){
		x += nx; y += ny;
	}
