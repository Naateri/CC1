class Polygon{
protected:
	PointArray *array;
	int instances;
public:
	Polygon();
	virtual const double area();// = 0;
	int getNumPolygons();
	int getNumSides();
	Point *getPoints();
};
