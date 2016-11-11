#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>  

using namespace std;

class Graph {
private:
	vector<int> start;
	vector<int> end;
	map<int, vector<int> > relation; //key_type = nodeID, data_type = adjacency
public:
	Graph(const vector<int> &starts, const vector<int> &ends){
		if (starts.size() != ends.size()){
			throw invalid_argument("Starts is not the same size as ends");
	} else {
			int i, j, s;
			s = starts.size();
			for (i = 0; i<s; i++)
				start.push_back(starts[i]); //metiendo a start
			for (i = 0; i<s; i++) //metiendo a end
				end.push_back(ends[i]);
			for (i = 0; i<s; i++){ //creando la relacion en un mapa
				vector<int> adjacency;
				for (j = 0; j<s; j++){
					if (start[i] == start[j]){
						adjacency.push_back(end[j]); //creando la relación de adyacencia (pero con todos los vertices de start, así se repitan)
					}
				}
				relation.insert(pair<int, vector<int> >(start[i], adjacency));
			
		}
	}
	};
	int numOutgoing(const int nodeID){
		if(relation.find(nodeID) == relation.end()){
			throw invalid_argument("That node doesn't exist");
		} else {
			
		int num, i, s;
		s = start.size();
		num = 0;
		for (i = 0; i<s; i++){
			if(start[i] == nodeID){
				num++;
			}
		}
		return num;
		}
	};
	const vector<int> adjacent(const int nodeID){
		if (relation.find(nodeID) == relation.end()){
			throw invalid_argument("That node doesn't exist");
		} else {
			return relation.find(nodeID)->second;
		}
	};
};

int main() {
	vector<int> beginning, finish, adjacency;
	beginning.push_back(1);
	beginning.push_back(1);
	beginning.push_back(1);
	beginning.push_back(5);
	beginning.push_back(5);
	beginning.push_back(4);
	finish.push_back(2);
	finish.push_back(3);
	finish.push_back(4);
	finish.push_back(4);
	finish.push_back(2);
	finish.push_back(2);
	Graph MyGraph(beginning, finish);
	cout << MyGraph.numOutgoing(1) << '\n';
	adjacency = MyGraph.adjacent(1);
	cout << "Adjacency: " << endl;
	for (int i = 0; i<adjacency.size(); i++){
		cout << adjacency[i] << " " << endl;
	}
	
	return 0;
}
