#include<iostream>
//#include "point.h"

class Vector{
private:
	Point Start, End;
public:
	Vector();
	Vector(Point Start1, Point End1);
	Vector(Vector &vec);
	void printVector();
	void modifyVectorStart(int nx, int ny);
	void modifyVectorEnd(int nx, int ny);
	double distancia(Point Start1, Point End1);
	
	
	
};
