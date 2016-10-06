#include <stdio.h>

/*void multimatrices(int mat1[][10], int mat2[][10], int result[][10], int n){
int i, j, k, result1, sum;
i = j = k = 0;
for (i; i<n; i++){
sum = 0;
for (j; j<n; j++){
for (k; k<n; k++){
result1 = mat1[i][k] * mat2[k][j];
sum += result1;
}
result[i][j] = sum;
}
}
}
*/
void ptrmultimatrices(int *mat1[], int *mat2[], int *resultadito[], int n){
	int i, j, k, result;
	int **mat11, **mat21, **mat31;
	int sum;
	i = j = k = 0;
	mat11 = mat1;
	mat21 = mat2;
	mat31 = resultadito;
	for(i; i<n; i++, *resultadito++, *mat1++){
		for (j; j<n ; j++, **mat31++, **mat21++){
			sum = 0;
			/* *mat11 = &mat1;*/
			for (k; k<n ; k++, **mat11++, *mat2++){
				result = (**mat11) * (**mat21);
				sum += result;
			}
			**mat31 = sum;
		}
	}

}


main() {
	int *a[2];
	int *b[2];
	int *c[2];
	int a1[2] = {1,2};
	int a2[2] = {3,4};
	int b1[2] = {1,1};
	int b2[2] = {1,1};
	int c1[2] = {0,0};
	int c2[2] = {0,0};
	int i, j;
	a[0] = a1;
	a[1] = a2;
	b[0] = b1;
	b[1] = b2;
	c[0] = c1;
	c[1] = c2;
/*	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	b[0][0] = 1;
	b[0][1] = 1;
	b[1][0] = 1;
	b[1][1] = 1;
	*/
	ptrmultimatrices(a, b, c, 2);
	i = j = 0;
	for (i; i<2; i++){
		printf("\n");
		for (j; j<2; j++){
			printf("%d\t", c[i][j]);
		}
	}
	return 0;
}

