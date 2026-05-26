#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class mifuncion{
    private:
        int x;
        int y;
    public:
        mifuncion(int a, int b):x(a), y(b){}
        int operator()(int z){
            return x*y*z;
        }
};

class Line{
    private:
        int a;
        int b;
    public:
        Line(int x, int y):a(x), b(y){}
        int operator()(int x){
            return (a*x)+b;
        }
};

template<class T>
class Line_T{
    private:
        T a;
        T b;
    public:
        Line_T(T x, T y):a(x), b(y){}
        T operator()(T x){
            return (a*x)+b;
        }
};

class Exp{
    private:
        int e;
    public:
        Exp(int x):e(x){}
        int operator()(int y){
            return pow(y,e);
        }
};

int main() {
    
    mifuncion f1(5,2); //configuración
    cout << f1(3) << endl;
    cout << endl;
    
    Line l1(4,2); //configuración
    for(int x = 1; x < 10; x++)
        cout << l1(x) << endl;
    Line_T<double> l2(3.4, 5.6);
    for(int x = 1; x < 10; x++)
        cout << l2(x) << endl;
    cout << endl;
    
    int arr[] = {1,2,3,4};
    Exp e(3);
    transform(arr, arr+4, arr, e);
    for(int* p = arr; p < arr+4; p++)
        cout << *p << endl;
    
    return 0;
}
