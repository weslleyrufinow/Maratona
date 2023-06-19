#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numbers[1000000];
int colors[1000000];

int selection_sort(int s[], int n) {
	int i,j,aux;
	int min;
	for (i=0; i<n; i++) {
		min=i;
		for (j=i+1; j<n; j++)
			if (s[j] < s[min]) 
				min=j;
		if (colors[min] != colors[i]) 
			return 0;
		aux = s[i];	s[i] = s[min]; s[min] = aux;
	}
	return 1;
}


int main() {
	clock_t start, end;
	int N, K;
	scanf("%d", &N);
	scanf("%d", &K);
	
	int n, c;
	for(int i = 0; i < N; i++){
		scanf("%d", &n);
		numbers[i] = n;
		scanf("%d", &c);
		colors[i] = c;
	}

	start = clock();
	if (selection_sort(numbers, N))
		printf("Y");
	else
		printf("N");
	end = clock();

	 double time;
	 time = (double)(end - start) / (double)(CLOCKS_PER_SEC);
	printf ("\nTempo total = %f", time);

	printf("\n");
	return 0;
}