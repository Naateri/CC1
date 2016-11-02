class VectorArray{
private:
	int _size;
	Vector *vector;
	void resize(int x);
public:
	VectorArray();
	VectorArray(Vector vectors[], int size);
	VectorArray(VectorArray &pv);
	~VectorArray();
	void push_back(Vector &p);
	void insert(int position, Vector &p);
	void remove(int position);
	int getSize();
	void clear();
	void printVArray();
};
