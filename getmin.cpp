#include <iostream>
using namespace std; 
template <typename T>
#define getmin(a,b) (a<b?a:b)

T mini(T a, T b){
	if (a<b){
		return a;
	} else {
		return b;
	}
}

int main() {
	cout << mini<int>(6,5) << endl;
	cout << mini<float>(3.4,6.9) << endl;
	cout << mini<char>('v','c') << endl;
	cout << "Preprocessor macros: " << endl;
	cout << getmin(6,5) << endl;
	cout << getmin(3.4,6.9) << '\n';
	cout << getmin('v','c') << endl;
	return 0;
}

