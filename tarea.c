#include <stdio.h>

int len(char a[])
{
	int x;
	for(x = 0; a[x] != '\0'; ++x)
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
/* Ejercicio 5.5 */
void strncpy(char s[], char t[], int n){
	int a = 0;
	while ((t[a] != '\0') && (a < n)){
		s[a] = t[a];
		a++;
	}
	s[a] = '\0';
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

int strncmpp(char s[], char t[], int n){
	int i = 0;
	for (i; s[i] == t[i]; i++){
		if (t[i] == '\0'){
			return 0;
		}
		/*if (n == i){
			break;
			if (t[i] == s[i]){
				return 0;
			} else {
				return s[i] - t[i];
			}
		}*/
	}
	return s[i] - t[i];
}
main()
{

	char s[] = "can";
	char t[] = "cion";
	char i[] = "Computer";
	char j[] = "Science";
	char k[] = "Scienceeee";
	char h[5];
		
	ptrstrcat(s,t);
	printf("ptr strcat: %s\n", s);
	printf("strend: %d\n", strend(i,j));
	strncpy(h, i, 3);
	printf("strncpy: %s\n", h);
	strncatt(i,j,5);
	printf("strncat: %s\n", i);
	printf("strncmp: %d\n", strncmpp(j,k,4));
		
}


