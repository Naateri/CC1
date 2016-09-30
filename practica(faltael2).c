#include <stdio.h>

/* 1. Calcula la suma de un arreglo utilizando punteros */



int sumaarray(int *array, int len){
	 
	int sum, i;
	sum = 0;
	for(i = 0; i < len; *array++, i++){
		sum += *array;
	}
	return sum;
}

/* 2. Calcula la multiplicacion de 2 matrices usando punteros */


void printmat(int mat[][10], int n){
	int i = 0;
	int j = 0;
	for (i; i<n; i++){
		for (j; j<n; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

/*void multimatrices(int mat1[][10], int mat2[][10], int result[][10], int n){
	int i, j, k, result1, sum;
	i = j = k = 0;
	for (i; i<n; i++){
		sum = 0;
		for (j; j<n; j++){
			for (k; k<n; k++){
				result1 = mat1[j][k] * mat2[k][j];
				sum += result1;
			}
			result[i][j] = sum;
		}
	}
}
*/
/*int ptrmultimatrices(int *mat1[], int *mat2[], int *resultadito[], int n){
	int i, j, k, result;
	int *mat11, *mat21, *mat31;
	int sum;
	i = j = k = 0;
	mat11 = &mat1[0];
	mat21 = &mat2[0];
	mat31 = &resultadito[0];
	for(i; i<n; i++, *resultadito++){
		sum = 0;
		for (j; i<n ; j++,*mat2++){
			for (k; i<n ; k++, *mat1++){
				result = (*mat1) * (*mat2);
				sum += result;
			}
		}
	}
	
}
*/
/* 3. Crear el tipo de dot (punto) y hallar la distancia entre dos puntos */

struct point {
	int x;
	int y;
};

void swap(int x, int y){
	int temp;
	temp = x;
	x = y;
	y = temp;
}
double distancia(struct point p1, struct point p2){
	int x1, y1, x2, y2, cateto1, cateto2;
	double dist;
	x1 = p1.x;
	x2 = p2.x;
	y1 = p1.y;
	y2 = p2.y;
	if(x2<x1){
		swap(x1, x2);
	}
	cateto1 = x2-x1;
	if(y2<y1){
		swap(y1, y2);
	}
	cateto2 = y2-y1;
	dist = sqrt((cateto1*cateto1)+(cateto2*cateto2));
	return dist;
	
	
	
}

main() {
	int array[] = {5,3,6,2,1};
	int mat1[2][2] = {{2,3},{1,2}};
	int mat2[2][2] = {{3,4},{2,1}};
	int result[2][2];
	struct point pt1;
	struct point pt2;
	pt1.x = 5;
	pt1.y = 6;
	pt2.x = 8;
	pt2.y = 10;
	/*multimatrices(mat1, mat2, result, 2);*/
	printf("Ejercicio 1: %d\n", sumaarray(array, 5));
	/*printf("Ejercicio 2: \n");
	printmat(result, 2);*/
	printf("Ejercicio 3: %f", distancia(pt1, pt2));
	
	
	
}

