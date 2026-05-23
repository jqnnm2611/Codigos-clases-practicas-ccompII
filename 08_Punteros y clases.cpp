#include <iostream>
using namespace std;

class MiClase{
  public:
  int x;
  int y;
  MiClase(int a, int b){
      x = a;
      y = b;
  }
  void imprimirx(){cout << x << endl;}
  void imprimiry(){cout << y << endl;}
};

class MiClase2{
  public:
  char x;
  char y;
  void imprimir(char z){
      cout << z << endl;
  }
};

int main() {
  
    
  MiClase uno(5,4);
  //Puntero a miembro dato
  int MiClase:: *p = &MiClase::x;
  cout << uno.*p << endl;
  p = &MiClase::y;
  cout << uno.*p << endl;
  //Puntero a método
  void(MiClase2:: *r)(char);
  r = &MiClase2::imprimir;
  MiClase2 obj;
  (obj.*r)('d');
    
  return 0;
}
