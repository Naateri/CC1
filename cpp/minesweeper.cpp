#include <iostream>
#include <stdlib.h> 
using namespace std;

int inputnrocol(string msj){
	int col;
	cout << msj;
	cin >> col;
	cout << endl;
	if (col<=0 || col >20){
		return inputnrocol("Ingrese un entero positivo menor a 20: ");
	}
	return col;
}
int inputnrofil(string msj){
	int fil;
	cout << msj;
	cin >> fil;
	cout << endl;
	if (fil<=0 || fil>20){
		return inputnrocol("Ingrese un entero positivo menor a 20: ");
	}
	return fil;
}

int nrominas(string msj, int fil, int col){
	int minas;
	cout << msj;
	cin >> minas;
	cout << endl;
	if (minas <=0 || minas >=(fil*col)){
		return nrominas("Ingrese un número válido: ", fil, col);
	}
	return minas;
	
}

void crearMatLet(string *mat[], int fil, int col, string txt){
	int i, j, k;
	for(k = 0; k < fil; k++)
		mat[k] = new string[20];
	for (i = 0; i<fil; i++){
		for (j = 0; j<col; j++){
			mat[i][j] = txt;
		}
	}
}

void crearMatNum(int *mat[], int fil, int col, int num){
	int i, j, k;
	for (k = 0; k<fil; k++)
		mat[k] = new int[20];
	for (i = 0; i<fil; i++){
		for (j = 0; j<col; j++){
			mat[i][j] = num;
		}
	}
}

void imprimirMatLet(string *mat[], int fil, int col){
	cout << "Su tablero va así: " << endl;
	int i, j;
	for (i = 0; i<fil; i++){
		for (j = 0; j<col; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void imprimirMatNum(int *mat[], int fil, int col){
	int i, j;
	for (i = 0; i<fil; i++){
		for (j = 0; j<col; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void insertBombitas(string *mat[], int bombitas, int fil, int col){
	int i, h, k;
	for (i = 0; i<bombitas; i++){
		do{
			h = rand() % fil;
			k = rand() % col;
		}while(mat[h][k] == "*");
		mat[h][k] = "*";
		
	}	
}

void contarBombitas(string *mat[], string *matriz[]){ //mat = visual, matriz = numeritos
	;
}

//atoi : convierte un string a int
void reverse(string s){
	int c, i, j;
	for (i = 0, j = s.length() - 1 ; i<j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
void itoa(int n, char *s){ //itoa: convierte un int a string
	int i, sign;
	if ((sign = n)<0)
		n = -n;
	i = 0;
	do{
		*s++ = n%10 + '0';
	} while((n/=10) > 0);
	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	reverse(s);
}

//arreglar reverse, ver como agregar los numeritos en la matriz
//como caracteres para poder agregar '*' en esa misma matriz
//y poder trabajar con todas sin problemas
//o si no #queChu y usar int 10 en vez de '*'
int main() {
	int col, fil, minas;
	//mat 1 = numeritos
	string *mat0[20], *mat1[20], *mat2[20], *mat3[20], fill1, fill2; //mat0 = visual, mat2 = bombitas, mat3 = ya pasó por acá (Y) o no (N) 
	fill1 = "_"; fill2 = "N";
	col = inputnrocol("Ingrese el número de columnas: ");
	fil = inputnrofil("Ingrese el número de filas: ");
	crearMatLet(mat0, fil, col, fill1);
	crearMatLet(mat2, fil, col, fill1);
	crearMatLet(mat3, fil, col, fill2);
	minas = nrominas("Ingrese el número de minas: ", fil, col);
	insertBombitas(mat2, minas, fil, col);
	imprimirMatLet(mat0, fil, col);
	imprimirMatLet(mat2, fil, col);
	return 0;
}

