#include <iostream>
#include <thread>

using namespace std;

void merge(int* inicio, int* mitad, int* fin) {

    int n1 = mitad - inicio + 1;
    int n2 = fin - mitad;

    int* izq = new int[n1];
    int* der = new int[n2];

    for(int i = 0; i < n1; i++)
        izq[i] = *(inicio + i);

    for(int i = 0; i < n2; i++)
        der[i] = *(mitad + 1 + i);

    int i = 0;
    int j = 0;
    int* p = inicio;

    while(i < n1 && j < n2){

        if(izq[i] <= der[j]){
            *p = izq[i];
            i++;
        }
        else{
            *p = der[j];
            j++;
        }

        p++;
    }

    while(i < n1){
        *p = izq[i];
        i++;
        p++;
    }

    while(j < n2){
        *p = der[j];
        j++;
        p++;
    }

    delete[] izq;
    delete[] der;
}

void mergeSort(int* inicio, int* fin){

    if(inicio >= fin)
        return;

    int* mitad = inicio + (fin - inicio)/2;

    mergeSort(inicio, mitad);
    mergeSort(mitad + 1, fin);

    merge(inicio, mitad, fin);
}

int main(){

    int arreglo[] = {18,4,9,1,30,15,7,20,5,12};

    int n = sizeof(arreglo)/sizeof(arreglo[0]);

    int* inicio = arreglo;
    int* fin = arreglo + n - 1;

    int* mitad = inicio + (fin - inicio)/2;

    thread t1(mergeSort, inicio, mitad);
    thread t2(mergeSort, mitad + 1, fin);

    t1.join();
    t2.join();

    merge(inicio, mitad, fin);

    cout<<"Arreglo ordenado:\n";

    for(int* p = inicio; p <= fin; p++)
        cout<<*p<<" ";

    cout<<endl;

    return 0;
}
