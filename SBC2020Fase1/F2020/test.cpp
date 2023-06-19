#include <iostream>
#include <time.h>
#include <iomanip>
#include <fstream>

using namespace std;

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

int* troca(int* atual, int &e, int &d){
    if(atual == &e){
        atual = &d;
    }else if(atual == &d){
        atual =  &e;
    }
return atual;}
/*
g++ test.cpp -o test && ./test
*/
int main(){
    std::ios::sync_with_stdio(0);
    int e,d, *atual;
    e = 1;
    d = 2;
    
    atual = &e;
    cout << *atual <<"\n" ;

    atual = troca(atual,e,d);
    cout << *atual <<"\n" ;

    atual = troca(atual,e,d);
    cout << *atual <<"\n" ;
    
    atual = troca(atual,e,d);
    cout << *atual <<"\n" ;       

    //double time; clock_t start, end;

    //arquivo(OK);
    //end = clock();//Momento do fim
    //tempo(time,start,end);//Funcao que retorna o intervalo de tempo
    
return 0;}
/*
g++ -g -O2 -std=gnu11 -static -lm name.cpp -o name; ./name.exe
g++ -g -O2 -std=gnu11 -static -lm 2020B.cpp -o test; ./test

g++ test.cpp -o test && ./test
g++ test.cpp -o test && ./Script.sh
g++ test.cpp -o test && ./ScriptTest.sh
*/