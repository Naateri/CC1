class Polygon{
protected:
	PointArray array;
	int instances;
public:
	Polygon();
	Polygon(Polygon &p);
	Polygon(Point Pls[], int i);
	virtual double area() = 0; //no need to declare it in polygon.cpp
	int getNumPolygons();
	int getNumSides();
	Point *getPoints();
};
