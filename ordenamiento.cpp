//Ana Maria Rodriguez Peña
//A01741831

#include <iostream>
#include <vector>
using namespace std;

//ordenaInsercion O(n^2)
int ordenaInsercion(vector<int> &v){
    int cont=-1;
    for (int i=1;i<v.size();i++){
        int j=i;
        while (j>0 && v[j]<v[j-1]){
            swap(v[j-1],v[j]);
            j--;
            cont++;
        }
        cont++;
    }
    return cont;
}

//ordenaBurbuja O(n^2)
int ordenaBurbuja(vector<int> &v){
    int cont=0;
    bool swapped;
    for (int i=0;i<v.size()-1;i++){
        swapped=false;
        for (int j=0;j<v.size()-1-i;j++){
            cont++;
            if (v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                swapped=true;
            }
        }
        if (!swapped) break;
    }
    return cont;
}

//ordenaMerge O(nlogn)
int ordenaMerge(vector<int> &v){
    int cont=0;
    if (v.size()<=1){
        return 0;
    }
    vector<int> izq, der;
    int mitad=v.size()/2;
    for (int i=0;i<mitad;i++){
        izq.push_back(v[i]);
    }
    for (int i=mitad;i<v.size();i++){
        der.push_back(v[i]);
    }
    cont+=ordenaMerge(izq);
    cont+=ordenaMerge(der);
    int i=0;
    int j=0;
    int k=0;
    while (i<izq.size() && j<der.size()){
        if (izq[i]<der[j]){
            v[k]=izq[i];
            i++;
        }
        else{
            v[k]=der[j];
            j++;
        }
        k++;
        cont++;
    }
    while (i<izq.size()){
        v[k]=izq[i];
        i++;
        k++;
    }
    while (j<der.size()){
        v[k]=der[j];
        j++;
        k++;
    }
    return cont;
}

//busqSecuencial O(n)
int busqSecuencial(vector<int>&v,int dato,int &cont){
    for (int i=0;i<v.size();i++){
        cont++;
        if (v[i]==dato){
            return i;
        }
    }
    return -1;
}

//busqBinaria O(logn)
int busqBinaria(vector<int>& v, int dato, int &cont) {
    int ini = 0;
    int fin = v.size() - 1;
    while (ini <= fin) {
        cont++;
        int mitad = (ini + fin) / 2;
        if (v[mitad] == dato) {
            return mitad;
        } else if (v[mitad] < dato) {
            ini = mitad + 1;
        } else {
            fin = mitad - 1;
        }
        cont++;
    }
    return -1;
}

int main(){
	vector<int> v1, v2, v3;
	int n, dato;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> dato;
		v1.push_back(dato);
		v2.push_back(dato);
		v3.push_back(dato);
	}
	cout << ordenaInsercion(v1) << " " << ordenaBurbuja(v2) << " " << ordenaMerge(v3) << endl;
	int q, pos;
	int cantBS, cantBB;
	cin >> q;
	for (int i=0; i<q; i++){
		cantBS = 0;
		cantBB = 0;
		cin >> dato;
		pos = busqSecuencial(v1, dato, cantBS);
		pos = busqBinaria(v1, dato, cantBB);
		cout << pos << " " << cantBS << " " << cantBB << endl; 
	}
}