class PointArray{
private:
	int _size;
	Point *point;
	void resize(int x);
public:
	PointArray();
	PointArray(Point points[], int size);
	PointArray(PointArray &pv);
	~PointArray();
	void push_back(Point &p);
	void insert(int position, Point &p);
	void remove(int position);
	int getSize();
	void clear();
	void printArray();
};
