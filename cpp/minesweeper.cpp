#include <iostream>
//#include <stdlib.h>
#include <cstdlib> 
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
	} //chvzguei
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

void contarBombitas(string *mat[], int *matriz[], int fil, int col){ //mat = visual, matriz = numeritos
	int x, y, c;
	for (x = 0; x < fil; x++){
		for (y = 0; y < col; y++){
			c = 0;
			if (x>0){
				if (y>0){
					if (mat[x-1][y-1] == "*"){
						c++;
					}
				}
				if (mat[x-1][y] == "*"){
					c++;
				}
				if (y < col-1){
					if(mat[x-1][y+1] == "*"){
						c++;
					}
				}
			}
			if (x < fil - 1){
				if (y>0){
					if (mat[x+1][y-1] == "*"){
						c++;
					}
				}
				if (y < col - 1){
					if (mat[x+1][y+1] == "*"){
						c++;
					}
				}
				if (mat[x+1][y] == "*"){
					c++;
				}
			}
			if (y>0){
				if (mat[x][y+1] == "*"){
					c++;
				}
			}
			if (y < col-1){
				if (mat[x][y+1] == "*"){
					c++;
				}
			}
			matriz[x][y] = c;
			if (mat[x][y] == "*"){
				matriz[x][y] = 10;
			}
		}
	}
}

int pedirCoordX(string msj, int fil){
	int xd;
	cout << msj << endl;
	cin >> xd;
	if (xd<0 || xd >fil){
		return pedirCoordX("Ingrese un número válido: ", fil);
	}
	return xd;
}
int pedirCoordY(string msj, int col){
	int y;
	cout << msj << endl;
	cin >> y;
	if (y < 0 || y > col){
		return pedirCoordY("Ingrese un número válido: ", col);
	}
	return y;
}
string convierte(int n){
	switch(n){
case 0:
	return "0";
	break;
case 1:
	return "1";
	break;
case 2:
	return "2";
	break;
case 3:
	return "3";
	break;
case 4:
	return "4";
	break;
case 5:
	return "5";
	break;
case 6:
	return "6";
	break;
case 7:
	return "7";
	break;
case 8:
	return "8";
	break;
case 9:
	return "9";
	break;
case 10:
	return "_";
	break;
	}
}
void revelar(int x, int y, string *mat[], string *mat1[], int *mat2[], int fil, int col){
	//mat = visual, mat1 = A,B; mat2 = numeritos
	if (mat2[x][y] == 10){
		imprimirMatLet(mat, fil, col);
		cout << "Usted ha perdido!" << endl;
		exit(69);
	} else {
	if (mat2[x][y] == 0){
		if ((x>0) && (x < fil)){
			if ((y>0) && (mat1[x-1][y-1] == "A")){
				mat1[x-1][y-1] = "B";
				if (mat2[x-1][y-1] == 10){
					mat[x][y] = "_";
				}
				if (mat2[x-1][y-1] != 10){
					mat[x-1][y-1] = convierte(mat2[x-1][y-1]);
					revelar(x-1, y-1, mat, mat1, mat2, fil, col);
				}
			}
			if ((y < col-1) && (mat1[x-1][y+1] == "A")){
				mat1[x-1][y+1] = "B";
				if (mat2[x-1][y+1] == 10){
					mat[x-1][y+1] = "_";
				}
				if (mat2[x-1][y+1] != 10){
					mat[x-1][y+1] = convierte(mat2[x-1][y+1]);
					revelar(x-1, y+1, mat, mat1, mat2, fil, col);
				}
			}
			if (mat1[x-1][y] == "A"){
				mat1[x-1][y] = "B";
				if (mat2[x-1][y] == 10){
					mat[x-1][y] = "_";
				}
				if (mat2[x-1][y] != 10){
					mat[x-1][y] = convierte(mat2[x-1][y+1]);
					revelar(x-1, y, mat, mat1, mat2, fil, col);
				}
			}
		}
		if (x < fil-1){
			if ((y>0) && mat1[x+1][y-1] == "A"){
				mat1[x+1][y-1] = "B";
				if (mat2[x+1][y-1] == 10){
					mat[x+1][y-1] = "_";
				}
				if (mat2[x+1][y-1] != 10){
					mat1[x+1][y-1] = convierte(mat2[x+1][y-1]);
					revelar(x+1, y-1, mat, mat1, mat2, fil, col);
				}
			}
			if ((y < col-1) && (mat1[x+1][y+1] == "A")){
				mat1[x+1][y+1] = "B";
				if (mat2[x+1][y+1] == 10){
					mat[x+1][y-1] = "_";
				}
				if (mat2[x+1][y+1] != 10){
					mat1[x+1][y+1] = convierte(mat2[x+1][y+1]);
					revelar(x+1, y+1, mat, mat1, mat2, fil, col);
				}
			}
			if (mat1[x+1][y] == "A"){
				mat1[x+1][y] = "B";
				if (mat2[x+1][y] == 10){
					mat[x+1][y] = "_";
				}
				if (mat2[x+1][y] != 10){
					mat[x+1][y] = convierte(mat2[x+1][y+1]);
					revelar(x+1, y+1, mat, mat1, mat2, fil, col);
				}
			}
		}
		if ((y>0) && (y < col)) { //revisar
			if (mat1[x][y-1] == "A"){
				mat1[x][y-1] = "B";
				if (mat2[x][y-1] == 10){
					mat[x][y-1] = "_";
				}
				if (mat2[x][y-1] != 10){
					mat[x][y-1] = convierte(mat2[x][y-1]);
					revelar(x, y-1, mat, mat1, mat2, fil, col);
				}
			}
		}
		if (y < col-1){
			if (mat1[x][y+1] == "A"){
				mat1[x][y+1] = "B";
				if (mat2[x][y+1] == 10){
					mat[x][y+1] = "_";
				}
				if (mat2[x][y+1] != 10){
					mat[x][y+1] = convierte(mat2[x][y+1]);
					revelar(x, y+1, mat, mat1, mat2, fil, col);
				}
			}
		}
	}
	mat1[x][y] = "B";
	mat[x][y] = convierte(mat2[x][y]);
}
}

bool ponerMina(){
	char asu;
	cout << "Desea poner una mina sobre esta posición?(s/n)" << endl;
	cin >> asu;
	if (asu == 's' || asu == 'S'){
		return true;
	} else {
		return false;
	}
}
int contarM(string *mat[], int fil, int col){
	int x, y, c;
	c = 0;
	for (x = 0; x < fil; x++){
		for (y = 0; y < col; y++){
			if (mat[x][y] == "M"){
				c++;
			}
		}
	}
	return c;
}

void matrizCompleta(string *mat0[], int *mat1[], string *mat2[], int fil, int col){
	int x, y;
	for (x = 0; x<fil; x++){
		for (y = 0; y<col; y++){
			if ((mat0[x][y] != "_" && mat2[x][y] != "*")){
			mat0[x][y] = convierte(mat1[x][y]);
			} else if (mat2[x][y] == "*") {
				mat0[x][y] = "*";
			}
		}
	}
}
int main() {
	int col, fil, minas, x, y, score, contarMi;
	int *mat1[20];
	bool xd;
	//mat 1 = numeritos
	string *mat0[20], *mat2[20], *mat3[20], fill1, fill2; //mat0 = visual, mat2 = bombitas, mat3 = ya pasó por acá (A) o no (B) 
	fill1 = "_"; fill2 = "A";
	score = 0;
	col = inputnrocol("Ingrese el número de columnas: ");
	fil = inputnrofil("Ingrese el número de filas: ");
	crearMatLet(mat0, fil, col, fill1);
	crearMatLet(mat2, fil, col, fill1);
	crearMatLet(mat3, fil, col, fill2);
	crearMatNum(mat1, fil, col, 0);
	minas = nrominas("Ingrese el número de minas: ", fil, col);
	insertBombitas(mat2, minas, fil, col);
	contarBombitas(mat2, mat1, fil, col);
	imprimirMatLet(mat0, fil, col);
	imprimirMatLet(mat2, fil, col);
	imprimirMatNum(mat1, fil, col);
	contarMi = contarM(mat0, fil, col);
	while ((score < minas)){ //agregar condición para que usuario no marque todas las M's y gane pe
		
	x = pedirCoordX("Ingrese la coordenada X: ", fil);
	y = pedirCoordY("Ingrese la coordenada Y: ", col);
	do{
		cout << "Usted ya pasó por este punto. Ingrese otro." << endl;
		x = pedirCoordX("Ingrese la coordenada X: ", fil);
		y = pedirCoordY("Ingrese la coordenada Y: ", col);
	} while((mat0[x][y] != "_") && (mat0[x][y] != "*"));
	xd = ponerMina();
	if (xd){
		if (mat0[x][y] == "M"){
			mat0[x][y] = "_"; //desmarcando
			imprimirMatLet(mat0, fil, col);
		} else {
			mat0[x][y] = "M";
			if (mat1[x][y] = 10){
				score++;
			}
			imprimirMatLet(mat0, fil, col);
		}
		
	} else {
		revelar(x, y, mat0, mat3, mat1, fil, col);
		imprimirMatLet(mat0, fil, col);
	}
	} //end while 
	if ((score == minas)){//&&
		matrizCompleta(mat0, mat1, mat2, fil, col);
		imprimirMatLet(mat0, fil, col);
		cout << "Ustead ha ganado!" << endl;
		exit(420);
	}
	return 0;
}


//mejorar revelar, matriz completa, revisar contador de bombitas, falta agregar
//unas cosas pero ya casi está op pe
//revisar condiciones para que acabe el juego

