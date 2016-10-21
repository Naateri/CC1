/*Class Element{
private:
	Point P;
	Element *next;
public:
	Element();
	Element(Point n);
	Point getVal();
	
};
*/
class PointArray{
private:
	int sizee;
	Point *point;
public:
	PointArray(Point points[], int size);
	PointArray(PointArray &pv);
	void push_back(Point &p);
	void insert(int position, Point &p);
	void remove(int position);
	int getSize();
	void clear();
};
