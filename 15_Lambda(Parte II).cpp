#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Producto{
    string nombre;
    double precio;
};

struct Comparador{
    bool operator()(const Producto& a, const Producto& b){
        return a.precio < b.precio;
    }
};

int main() {
    
    vector<Producto> items = {{"lapicero",15.99},{"laptop",999.99},{"libro",35.89}};
    //sort(items.begin(),items.end(),Comparador());
    sort(items.begin(),items.end(),[](const Producto& a, const Producto& b){
        return a.precio < b.precio;
    });
    
    //Forma 1 (mía)
    for(const Producto& p : items){
        cout << p.nombre << "," << p.precio << endl;
    }
    
    //Forma 2 (profe)
    for(vector<Producto>::iterator it = items.begin(); it != items.end(); it++)
        cout << it->nombre << ' ';
    cout << endl;
    
    return 0;
}










