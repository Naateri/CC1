class Polygon{
protected:
	PointArray *array;
	int instances;
public:
	double area();
	int getNumPolygons();
	int getNumSides();
	Point *getPoints();
};
