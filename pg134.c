#include <stdio.h>
struct key{
	char *word;
	int count;
} *keytab = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0,
};

struct key *binsearch(char *word, struct key *tab, int n){
	int cond;
	int cont;
	struct key *low = &tab[0];
	struct key *high = &tab[n];
	struct key *mid;
	cont = 0;
	/*low = 0;
	high = n-1;*/
	while (low < high){
		mid = low + (high-low)/2;
		/*while (cont < mid){
			cont++;
			*tab++;
		*/
		if ((cond = strcmp(word, mid -> word)) < 0)
			high = mid;
		} else if (cond > 0) {
		low = mid + 1;
		} else {
		return mid;
	}
		
	}
	return -1;
}

main() {
	
	printf("%d", binsearch("break", struct key *keytab, 11);
	
}

