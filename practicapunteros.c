#include <stdio.h>

int len(char a[])
{
	int x;
	for(x = 0; a[x] != '\0'; ++x)
		;
	return x;
}

int ptrlen(char *a){
	int x;
	for (x = 0; *a != '\0'; x++)
		;
	return x;
}

/* Ejercicio 5.3 */
char* strcat(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (s[i] != '\0')
		i++;
	while ((s[i++] = t[j++]) != '\0')
		;
	return s;
	
}

void ptrstrcat(char *s, char *t){
	while (*s != '\0'){
		s++;
	}
	for ( ; (*s = *t) != '\0'; s++, t++){
		;
	}
}

/* Ejercicio 5.4 */	
int strend(char r[], char j[]){
	int x, y, z, n;
	n = 0;
	x = len(r);
	y = len(j);
	z = x-y;
	while ((r[z] == j[n]) && r[z] != '\0'){
		z++;
		n++;
	}
	if (j[n] == '\0'){
		return 1; /* si acaban en lo mismo */
	} else {
		return 0; /* si no acaban en lo mismo */
	}
}
int ptrstrend(char *r, char *j){
	int x, y;
	x = len(r);
	y = len(j);
	while (y < x){
		r++;
		y++;/*para que apunte a la misma cantidad de elementos finales en r y j */
	}
	while ((*r == *j) && *r != '\0'){
		r++;
		j++;
	}
	if (*r == '\0'){
		return 1;
	} else {
		return 0;
	}
	
}
/* Ejercicio 5.5 */
void strncpy(char s[], char t[], int n){
	int a = 0;
	while ((t[a] != '\0') && (a < n-1)){
		s[a] = t[a];
		a++;
	}
	s[a] = '\0';
}

void ptrstrncpy(char *s, char *t, int n){
	int a = 0;
	while(((*s = *t) != '\0') && (a<n-1)){ 
		s++;
		t++;
		a++;
	}
	s++;
	*s = '\0';
}
void strncatt(char s[], char t[], int n){
	int i, j;
	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	while ((t[j] != '\0') && (j < n)){
		s[i] = t[j];
		i++;
		j++;
	}
	s[i] = '\0';
	/*return s;*/
}

void ptrstrncat(char *s, char *t, int n){
	int i;
	while (*s != '\0'){
		s++;
	}
	for (i = 0; (*s = *t) != '\0', i<n-1; i++, s++, t++){
		;
	}
	s++;
	*s = '\0';
}

int strncmpp(char s[], char t[], int n){
	int i = 0;
	for (i; s[i] == t[i]; i++){
		if (t[i] == '\0'){
			return 0;
		}
		if (n == i){
			break;
			if (t[i] == s[i]){
				return 0;
			} else {
				return s[i] - t[i];
			}
		}
	}
	return s[i] - t[i];
}

int ptrstrncmp(char *s, char *t, int n){
	int i = 0;
	for (i; *s == *t; s++, t++, i++){
		if (*t == '\0'){
			return 0;
		}
		if (n == i){
			break;
			if (*t == *s){
				return 0;
			} else {
				return *s - *t;
			}
		}
	}
	return *s - *t;
}
int ptrstrindex(char *s, char *t){
	int n = 1;
	for (n; *s != '\0'; *s++, n++){
		if (*s == *t){
			return n;
		}
	}
	return -1;
	
}

int ptrgetline(char *s, int lim){
	int c, i;
	for (i = 0; i < lim-1 && (c=getchar())!=EOF && c != '\n'; ++i){
		*s = c;
	}
	if (c == '\n'){
		*s = c;
		++i;
	}
	*s = '\0';
	return i;
}

int ptratoi(char *s){
	int n, sign;
	for (; isspace(*s); s++)
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	n = 0;
	for ( ; *s >= '0' && *s <= '9'; s++){
		n = 10 * n + (*s - '0');
	}
	return sign * n;
}

/*void ptrreverse(char *s){
	int c, i, j;
	char *d;
	d = &s[0];
	while (*d != '\0'){
		d++;
	}
	for (i = 0, j = len(s) - 1; i<j; i++, j--, s++, d--){
		c = *s;
		*s = *d;
		*d = c;
	}
} ARREGLAR
*/

void ptritoa(int n, char *s){
	int i, sign;
	if ((sign = n) < 0){
		n = -n;
	}
	do { /* generar digitos en orden contrario */
		*s++ = n % 10 + '0'; /* conseguir siguiente digito */
	} while((n /= 10) > 0); /* borrarlo */
	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	/* ptrreverse(s)*/ 
}
main()
{
	
	char s[] = "can";
	char t[] = "cion";
	char i[] = "Computer";
	char j[] = "Science";
	char k[] = "Scienceeee";
	char h[10];
	char a[] = "+158";
	char b[] = "hola";
	int c = 6901;
	char d[5];
	
	ptrstrcat(s,t);
	printf("ptr strcat: %s\n", s);
	printf("ptr strend: %d\n", ptrstrend(i,j));
	ptrstrncpy(h, i, 3);
	printf("ptr strncpy: %s\n", h);
	ptrstrncat(i,j,4);
	printf("ptr strncat: %s\n", i);
	printf("ptr strncmp: %d\n", ptrstrncmp(j,k,4));
	printf("ptr strindex: %d\n", ptrstrindex(k, "i"));
	printf("ptr atoi: %d\n", ptratoi(a));
	/*ptrreverse(b);
	printf("ptr reverse: %s\n", b);
	ptritoa(c, d);
	printf("ptr itoa (falta revertir): %s\n", d);*/
	
	
}
