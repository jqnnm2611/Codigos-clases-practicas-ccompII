#include <iostream>
#include <utility>
using namespace std;

class SmartPointer{
    private:
        int* ptr;
    public:
        explicit SmartPointer(int* p = nullptr): ptr(p){}
        ~SmartPointer(){delete ptr;}
        
        int& operator*(){return *ptr;}
        int* operator->(){return ptr;}
        SmartPointer& operator=(SmartPointer&& other) noexcept{
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
            cout << "operator = de movimiento" << endl;
            return *this;
        }
        
        SmartPointer(const SmartPointer&) = delete;
        
};

//PROGRAMACIÓN GENÉRICA (TEMPLATE)

template<class T>
T f1(T dato){
    return dato + 1;
}

/*
template <class T>
class SmartPointer{
    private:
        T* ptr;
    public:
        explicit SmartPointer(T* p = nullptr): ptr(p){}
        ~SmartPointer(){delete ptr;}
        
        T& operator*(){return *ptr;}
        T* operator->(){return ptr;}
        SmartPointer& operator=(SmartPointer&& other) noexcept{
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
            cout << "operator = de movimiento" << endl;
            return *this;
        }
        
        SmartPointer(const SmartPointer&) = delete;
        
};
*/

int main() {
    
  SmartPointer q(new int(10));
  //SmartPointer<int> q(new int(10));
  SmartPointer p;
  //SmartPointer<int> p;
  p = move(q); //operator = de movimiento
  cout << *p << endl;

  cout << f1(5.4) << endl;
    
  return 0;
}
