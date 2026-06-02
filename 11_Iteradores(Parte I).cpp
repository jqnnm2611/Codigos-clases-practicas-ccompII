#include <iostream>
#include <vector>
using namespace std;

bool mult(int x){
    if(x % 2 == 0)
        return true;
    return false;
}

class multi{
    private:
        int y;
    public:
        multi(int a):y(a){}
        bool operator()(int x){
            if(x % y == 0)
                return true;
            return false;
        }
};

//Función usando función
/*vector<int> find_matching(vector<int> v, bool(*f)(int, int)){
    vector<int> res;
    vector<int>::iterator it = v.begin();
    vector<int>::iterator end = v.end();
    while(it != end){
        if(f(*it, 2))
            res.push_back(*it);
        it++;
    }
    return res;
}*/

//Función usando functor
/*vector<int> find_matching(vector<int> v, multi m){
    vector<int> res;
    vector<int>::iterator it = v.begin();
    vector<int>::iterator end = v.end();
    while(it != end){
        if(m(*it, 2))
            res.push_back(*it);
        it++;
    }
    return res;
}*/

//Función usando templates
template<class T>
vector<int> find_matching(vector<int> v, T m){
    vector<int> res;
    vector<int>::iterator it = v.begin();
    vector<int>::iterator end = v.end();
    while(it != end){
        if(m(*it))
            res.push_back(*it);
        it++;
    }
    return res;
}

int main() {
    
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    
    bool(*f1)(int) = mult;   //función
    multi m1(2);   //functor
    vector<int> v2 = find_matching(v1, f1);
    vector<int>::iterator it = v2.begin();
    vector<int>::iterator end = v2.end();
    while(it != end){
      cout << *it << ',';
      it++;
    }
    cout << endl;
    
    return 0;
}
