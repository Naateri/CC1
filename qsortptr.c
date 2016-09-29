#include <stdio.h>

void swap(char *v[], int i, int j){
	char *d;
	char *temp;
	int temp2;
	int k = 0;
	d = &v[0][0];
	if (i>j){
		temp2 = i;
		i = j;
		j = temp2;
	}
	while ((*d != '\0')&&(k<i)){
		d++;
		j++;
	}
	
	temp = *v;
	*v = *d;
	*d = temp;	
}

void qsort(char *v[], int left, int right){
	int i, last, cont;
	char *ptr;
	ptr = &v[0][0];
	cont = 0;
	if (left >= right){
		return;
	}
	swap (v, left, ((left+right)/2));
	last = left;
	while (cont < left){
		cont ++;
		*ptr++;
	}
	for (i = left + 1; i<= right; i++){
		if (strcmp(v, ptr) < 0){
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}


main() {
	
	char *p[] = {"hola", "tal", "que"};
	qsort(p, 0, 2);
	printf("%s", p);
	
	
}

