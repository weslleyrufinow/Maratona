#include <iostream>
#include <time.h>
#include <iomanip>
#include <fstream>

#define TAM 10

using namespace std;

char horizontal(int l, int r, int c, int matriz[TAM][TAM], char &OK){
    int i=0;
    //Se o tamanho do barco for maior que a qtd de espacos, eh invalido
    if((c+l)-1 > TAM){ 
        OK='N';
        return(OK);
    }
    while(i != l){
        if(matriz[r][c]==1){//Se a posição já estiver marcada, um barco passou por cima do outro, eh invalido
            OK='N';
            return(OK);
        }
        matriz[r][c]=1;//Marco a posicao do barco na matriz
        c++;
        i++;
    }
return(OK);}

char vertical(int l, int r, int c, int matriz[TAM][TAM], char &OK){
    int i=0;
    //Se o tamanho do barco for maior que a qtd de espacos, eh invalido
    if((r+l)-1 > TAM){ 
        OK='N';
        return(OK);
    }
    while(i != l){       
        if(matriz[r][c]==1){//Se a posição já estiver marcada, um barco passou por cima do outro, eh invalido
            OK='N';
            return(OK);
        }
        matriz[r][c]=1;//Marco a posicao do barco na matriz
        r++;
        i++;
    }
return(OK);}

void printMatriz(int matriz[TAM][TAM]){
    int i, j;
    cout <<"  ";
    for(i=0;i<TAM;i++){
        cout <<" "<<i;
    }
    cout << "\n";
    for(i=0; i<TAM; i++){
        (i<10)?(cout <<" "<< i << " "):(cout << i << " "); 
        for(j=0; j<TAM; j++){
            cout << matriz[i][j] << " ";
        }
        cout <<"\n";
    }
}
void tempo(double &time, clock_t &start, clock_t &end){
	time = (double)(end - start) / (double)(CLOCKS_PER_SEC);
    cout << " Tempo total= "<< time << "\n" << setprecision(10);
}

void arquivo(char &OK){
    //remove("GBAll.txt"); apaga arquivos no diretório atual
    ofstream arq;
    arq.open("GBAll.txt",ios::app);
    arq << OK <<"\n";
    arq.close();    
}

int main(){
    std::ios::sync_with_stdio(0);
    //double time; clock_t start, end;
    
    int matriz[TAM][TAM] = {0},i,n,d,l,r,c;
    char OK = 'Y';

    cin >> n;
    
    //start = clock(); //Momento de inicio
    for(i=0;i<n;i++){
        cin >> d >> l >> r >> c;
        r-=1;
        c-=1;
        (d==0)?(horizontal(l,r,c,matriz,OK)):(vertical(l,r,c,matriz,OK));
    }
    
    printMatriz(matriz);

    cout<< OK <<"\n";
    arquivo(OK);
    //end = clock();//Momento do fim
    //tempo(time,start,end);//Funcao que retorna o intervalo de tempo
    
return 0;}
/*
g++ -g -O2 -std=gnu11 -static -lm name.cpp -o name; ./name.exe
g++ -g -O2 -std=gnu11 -static -lm 2020B.cpp -o 2020B.out; ./2020B.out

g++ B2020.cpp -o B2020.out && ./ScriptTest.sh
*/