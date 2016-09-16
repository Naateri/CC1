#include <stdio.h>
/*1. Escriba una función lower, la cual convierte letras mayusculas a minusculas usando una condicional. No usar if-else. */

char* convertir(char s[]){
	s[0] = s[0] + 'a' - 'A';
	return s;
}
/*2. Escriba una función strindex(s, t), la cual retorne la posición de la ocurrencia mas a la derecha de t en s. Retorne -1 si no la encuentra. */

int strindex(char s[], char t[]){
	int i = 0;
	for (i; s[i] != '\0'; i++){
		if (s[i] == t[0]) {
			return i;
		}
	}
	return -1;
}


/*3. Escriba una función recursiva que reciba un string y devuelva el string invertido (sin utilizar la libreria string.h).*/

char *invertir(char s[], char d[], int n, int size){/*d es un array vacio del tamaño de s, n debe valer 0 al comienzo siempre*/
	int i;
	if (n == size){
		d[n] = '\0';
		return d;
	}
	i = size-n-1;
	d[n] = s[i];
	n++;
	return invertir(s, d, n, size);
	
}

int strlength(char s[]){
	int n = 0;
	while (s[n] != '\0'){
		n++;
	}
	return n;
}


/*4. Escriba un programa que reciba un string de la forma "123.45e-6" y devuelva su correspondiete número.*/
float convertir2(char s[]){
	
	
	double val, power, power2, num;
	int i, n, sign, cont;
	i = 0;
	if (s[i] == '-'){
		sign = -1;
		i++;
	} else if (s[i] == '+'){
		sign = 1;
		i++;
	} else {
		sign = 1;
	}
	for (val = 0.0; s[i] >= '0' && s[i] <= '9'; i++){
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.'){
		i++;
	}
	for (power = 1.0; s[i] >= '0' && s[i] <= '9'; i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	num = sign*val/power;
	if (s[i] == 'e'){
		i++;
	}
	if (s[i] == '+'){
		i++;
		for (n=0; s[i] >= '0' && s[i] <= '9'; i++){
			n = 10*n + (s[i]-'0');
		}
		cont = n;
		for (power2 = 1.0; cont > 0; cont--){
			power2 *= 10.0;
		}
		return num * power2;
	}
	else if (s[i] == '-'){
		i++;
		for (n=0; s[i] >= '0' && s[i] <= '9'; i++){
			n = 10*n + (s[i]-'0');
		}
		cont = n;
		for (power2 = 1.0; cont > 0; cont--){
			power2 *= 10.0;
		}
		return num / power2;
	}
}
main() {
	
	char letra[] = "Y";
	char d[] = "queso";
	int n = strlength(d);
	char d1[n];
	char s1[] = "Hello";
	char s11[] = "l";
	int b = strindex(s1, s11);
	char s[] = "5.644e+4";
	float a;
	printf("1. Funcion que convierte caracter de mayuscula a minuscula.\nSe recibe: Y\nSe retorna: %s\n", convertir(letra));
	printf("2. Funcion strindex:\nSe busca el caracter %s en la palabra Hello (empezando de 0). Retorna %d\n", s11, b);
	a = convertir2(s);
	printf("3. Funcion recursiva que invierte un string\nSe recibe el string \"queso\", se retorna: %s\n", invertir(d, d1, 0, n));
	printf("4. Funcion convertir:\nEl caracter a convertir es 5.644e+4. Retorna %f\n", a);	
}
