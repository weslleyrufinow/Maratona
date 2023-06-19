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

int* troca(int* atual, int &PL, int &PR){
    if(atual == &PL){
        atual = &PR;
    }else if(atual == &PR){
        atual =  &PL;
    }
return atual;}

int game(int &PL, int &PR, int &GL, int &GR){
    int dif;

    if(PL == 10){
        GL+=1;
        return 1;
    }else if(PR == 10){
        GR+=1;
        return 2;
    }

    dif = PL - PR;
    if(dif<=0){
        dif *= -1;
    }

    if((PL!=PR)&&(dif>=2)&&(PL>=5)&&(PR>=5)){
        if(PL>PR){
            GL+=1;
            return 1;
        }else{
            GR+=1;
            return 2;
        }
    }
return 0;}
/*
g++ F2020.cpp -o F2020 && ./F2020
g++ F2020.cpp -o F2020 && ./ScriptTest.sh
*/
int main(){
    std::ios::sync_with_stdio(0);
    //double time; clock_t start, end;
    
    int PL,PR,GL,GR,*atual,i,res;
    string word;

    PL = PR = GL = GR =0;

    cin >> word;
    atual = &PL;
    for(i=0; i< (int)word.size();i++){
        if(word[i] == 'S'){
            *atual+=1;
        }else if(word[i] == 'R'){
            atual = troca(atual,PL,PR);
            *atual+=1;
        }else if(word[i] == 'Q'){
            printf("%d (%d) - %d (%d)\n",GL,PL,GR,PR);      
            res = game(PL,PR,GL,GR);
            if(res == 1){
                PL = PR = 0;
                atual = &PL;
            }else if(res == 2){
                PL = PR = 0;
                atual = &PR;
            }      
        }
    }

    //arquivo(OK);
    //end = clock();//Momento do fim 
    //tempo(time,start,end);//Funcao que retorna o intervalo de tempo
    
return 0;}
/*
g++ -g -O2 -std=gnu11 -static -lm name.cpp -o name; ./name.exe
g++ -g -O2 -std=gnu11 -static -lm 2020B.cpp -o F2020; ./F2020

g++ -g -Wall -Werror F2020.cpp -o F2020 && ./F2020
g++ F2020.cpp -o F2020 && ./F2020
g++ F2020.cpp -o F2020 && ./ScriptTest.sh
g++ F2020.cpp -o F2020 && ./Script.sh
*/