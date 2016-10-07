#include <stdio.h>

void ptrmultimatrices(int *mat1[], int *mat2[], int *resultadito[], int m, int n, int p){ 
	/* m = filas mat1, n = columnas mat1/filas mat2, p = columnas mat3 */
	int i, j, k, result, sum;
	i = 0;
	for(i; i<m; i++){
		for (j = 0; j<p ; j++){
			sum = 0;
			for (k = 0; k<n ; k++){
				result = mat1[i][k] * mat2[k][j] ;
				sum += result;
			}
			resultadito[i][j] = sum;
		}
	}
	
}


main() {
	int *a[5];
	int *b[5];
	int *c[5];
	int a1[2] = {1,3};
	int a2[2] = {2,4};
	int a3[2] = {3,1};
	int b1[3] = {3,2,1};
	int b2[3] = {2,1,3};
	int c1[5];
	int c2[5];
	int i, j;
	for (i = 0; i<5; i++)
		c1[i] = 0;
		c2[i] = 0;
	a[0] = a1;
	a[1] = a2;
	a[2] = a3;
	b[0] = b1;
	b[1] = b2;
	c[0] = c1;
	c[1] = c2;
	ptrmultimatrices(b, a, c, 2, 3, 2);
	i = 0;
	for (i; i<2; i++){
		printf("\n");
		for (j = 0; j<2; j++){
			printf("%d ", c[i][j]);
		}
	}
	return 0;
}
