#include <iostream>
using namespace std;

template<class T>  //predefinición de la clase Vector
class Vector;

template<class T>
class Iterator{
    T* it;
    public:
        friend class Vector<T>;  //se declara como clase amiga para acceder a su parte privada (parte del operador ++)
        Iterator(){  //Constructor por defecto
            it = nullptr;
        } 
        Iterator(T* itr){  //Constructor parametrizado (usado 3 veces en el código)
            it = itr;
        }
        bool operator!=(Iterator& otro){  //sobrecarga del !=
            return it != otro.it;
        }
        T operator*(){  //sobrecarga de *  
            return *it;
        }
        Iterator operator++(int){  //sobrecarga de ++ (accediendo a la parte privada de Vector)
            it++;
            return *this;
        }
        void operator=(T val){  //sobrecarga de = (asignación de valores)
            *it = val;
        }
        void operator=(Iterator otro){  //sobrecarga de = (asignación entre iteradores). No es necesario para casos como el del cout del main porque vuelve a repetir el proceso realizado cuando se creó por primera vez ese iterador [ itr = vec.begin(); ], pero sí en el caso que se desee asignar un iterador creado personalmente a otro [ Vector::iter itr2 = itr; ]
            it = otro.it;
        }
};

template<class T>
class Vector{
    T a[5];
    public:
        typedef Iterator<T> iter;
        iter begin(){
            return iter(&a[0]);
        }
        iter end(){
            return iter(&a[5]);
        }
};

int main() {
    
    Vector<int> vec;
    Vector<int>::iter itr = vec.begin();
    Vector<int>::iter end = vec.end();
    int dato = 1;
    while(itr != end){
        itr = dato;
        itr++;
        dato++;
    }
    
    itr = vec.begin();
    while(itr != end){
        cout << *itr << " ";
        itr++;
    }
    
    return 0;
}
