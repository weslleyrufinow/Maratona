#include <iostream>
#include <vector>

    using namespace std;

int main(){
    // vector<int> a[1000001] = {0};
    int vetor[1000001] = {0};
    int aux, i, n = 0;

    cin >> n;
    vector<int> a;
    vector<int> b;

    for(i=0 ; i<n; i++){
        cin >> aux;
        a.push_back(aux);
    }

    for(i=0 ; i<n; i++){
        cin >> aux;
        b.push_back(aux);
    } 

    vector<int> c;
    vector<int> d;
    for(i=0 ; i<(n*2); i++){
        aux = a[i] + b[i];
        c.push_back(aux);
        aux = a[i] - b[i];
        d.push_back(aux);        
    }

    for(i=0 ; i<n; i++){
        cout << c[i] << " ";
    }
    cout << "\n";
    
    for(i=0 ; i<n; i++){
        cout << d[i] << " ";
    }    

return 0;}