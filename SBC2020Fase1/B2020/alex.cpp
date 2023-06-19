/*
** Maratona de Programação da SBC – ICPC – 2020
** 1a Fase - Problema B - Batalha Naval
*/
#include <stdio.h>
#include <fstream>

using namespace std;

int mar[11][11] = {0};
char resp = 'Y';
int N, D, L, R, C;

void arquivo(char &OK){
    //remove("GBAll.txt"); apaga arquivos no diretório atual
    ofstream arq;
    arq.open("GBAll.txt",ios::app);
    arq << OK <<"\n";
    arq.close();    
}

int horizontal(int L, int R, int C){
	for (int c = C; c <= C+L-1; ++c){
		if (mar[R][c] == 0)
			mar[R][c] = 1;
		else
			return 0;
	}
	return 1;
}

int vertical(int L, int R, int C){
	for (int r = R; r <= R+L-1; ++r){
		if (mar[r][C] == 0)
			mar[r][C] = 1;
		else
			return 0;
	}
	return 1;
}

int main(){
	scanf("%d", &N);
	while(scanf("%d %d %d %d", &D, &L, &R, &C) != EOF)
		if (D == 0){
			if (!horizontal(L, R, C)){
				resp = 'N';
				break;
			}
		}
		else{
			if (!vertical(L, R, C)){
				resp = 'N';
				break;
			}
		}
	printf("%c\n", resp);
	arquivo(resp);
	return 0;
}
/*
g++ alex.cpp -o alex && ./teste.sh
*/