class Point{
private:
	int x, y;
public:
	Point();
	Point(int nx, int ny);
	Point(Point &o);
	void setx(int nx);
	void sety(int ny);
	int getx();
	int gety();
	void printPoint();
	void modifyPoint(int nx, int ny);
};
