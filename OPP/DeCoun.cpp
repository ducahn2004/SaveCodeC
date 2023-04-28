#include <iostream>
using namespace std;

class A{
    public:
        A(){
            cout << "A";
        }
        ~A(){
            cout << "B";
        }
};
class B: public A{
    public:
        B():A(){
            cout << "C";
        }
        ~B(){
            cout << "D";
        }
};
class D{
    private:
        int x;
        int y;
    public:
        D(int x, int y) : x(x),y(y){}
};
void arg(B &b){}

int main(){
    B b;
    arg(b);
    return 0;
}
// constructor lop cha truoc , lop con sau
// destructor lop con truoc , lop cha sau