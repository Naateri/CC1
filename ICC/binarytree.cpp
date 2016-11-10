#include <iostream>
using namespace std;

struct nodito{
	int niqui_value;
	nodito *left;
	nodito *right;
};
class BinaryTree{
private:
	struct nodito *root;
public:
	BinaryTree(){
		struct nodito *roott;
		roott = new nodito;
		roott = NULL;
		this->root = roott;
	};
	BinaryTree(int val){
		struct nodito *roott;
		roott = new nodito;
		roott->niqui_value = val;
		roott->left = NULL;
		roott->right = NULL;
		this->root = roott;
	}
	void insertarApurate(int val){
		if (root == NULL){
			struct nodito *leaf;
			leaf = new nodito;
			leaf->niqui_value = val;
			leaf->right = NULL;
			leaf->left = NULL;
			root->left = leaf;
		} else {
			if (val < (root->niqui_value)){
				if (root->left == NULL){
					struct nodito *leaf;
					leaf = new nodito;
					leaf->niqui_value = val;
					leaf->right = NULL;
					leaf->left = NULL;
					root->left = leaf;
				} else {
					root = root->left;
					insertarApurate(val);
					
				}
				
			} else {
				if (root->right == NULL){
				struct nodito *leaf;
				leaf = new nodito;
				leaf->niqui_value = val;
				leaf->right = NULL;
				leaf->left = NULL;
				root->right = leaf;
				} else {
					root = root->right;
					insertarApurate(val);
				}
			}
		}
	};
	void visitaPreOrden(){
		struct nodito *guide, *guide2;
		guide = root; guide2 = root;
		if (guide != NULL){
			cout << root->niqui_value << endl;
		}
		if (guide->left != NULL){
			root = guide->left;
			visitaPreOrden();
			root = guide2;
		}
		if (guide->right != NULL){
			root = guide->right;
			visitaPreOrden();
			root = guide2;
		}
	};
	void visitaInOrden(){
		if (root != NULL){
			
		}
	};
	void visitaPostOrden(){
		if (root->left != NULL){
			root = root->left;
			if (root->left == NULL){
				cout << root->niqui_value << endl;
			}
			visitaPostOrden();
		}
		if (root->right != NULL){
			root = root->right;
			visitaPostOrden();
		}
		if (root != NULL){
			;
		}
	}
};

int main() {
	
	BinaryTree PLS(2);
	PLS.insertarApurate(1);
	PLS.insertarApurate(5);
	PLS.insertarApurate(4);
	PLS.insertarApurate(7);
	PLS.insertarApurate(6);
	PLS.visitaPreOrden();
	return 0;
}

//arreglar visitas
