#include <iostream>
using namespace std;
int main(){
    std::ios::sync_with_stdio(0);
    int T, D, M, I, A , B;
    char R = 'N';
    A = 0; //Iniciando auxiliar com o intervalo 0

    cin >> T >> D >> M;

    for(I=0; I<M; I++){//Compara desde o inicio, e com os valores lidos
        cin >> B;
        if(B - A >= T){
            R = 'Y';
        }
        A = B;
    }
    if(M - A >= T){//Compara com a duracao total do voo
        R = 'Y';
    }
    cout << R;
    
return 0;}
/*
g++ -g -O2 -std=gnu11 -static -lm
g++ -g -O2 -std=gnu11 -static -lm K.cpp -o K; ./K.exe
g++ K.cpp -o K; ./K.exe
*/