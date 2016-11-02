//class Point;
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
	double distancia();
	void setStart(int nx, int ny);
	void setEnd(int nx, int ny);
	int getStartX();
	int getStartY();
	int getEndX();
	int getEndY();
	void modifyVector(Point Start1, Point End1);
};
