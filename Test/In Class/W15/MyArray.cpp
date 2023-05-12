#include <iostream>
#include <cstring>
#include <string>
#include <math.h>

using namespace std;


class String{

private:
    int length;
    char* str;

public:
    String(const char* _str){
        str = new char[strlen(_s    tr) + 1];
        strcpy(str,_str);
        *(str + strlen(_str)) = '\0';
        length = strlen(str);
    }

    //setter
    void setContent(const char* _str){
        str = new char[strlen(_str) + 1];
        strcpy(str,_str);
        *(str + strlen(_str)) = '\0';
        length = strlen(str);
    }

    //getter
    int getLength(){return length;};
    char* getStr(){return str;}

    //member function
    void print(){
        for(int i = 0; i <= length; i++){
            cout << *(str + i);
        }
        cout << endl;
    }

    void append(const char* _str){
        char* temp = new char[length + strlen(_str) + 1];
        strcpy(temp, str);
        strcpy(temp + length, _str);
        *(temp + length + strlen(_str)) = '\0';
        str = temp;
        length = strlen(str);
    }

    String clone(){
        String temp = String(str);
        return temp;
    }

    //Deductor
    ~String(){
        delete[] str;
    }
};

int main(){
    cout << "Test 1: " << endl;
    String s("Hello");
    cout << "s.getLength() " << s.getLength() << endl;
    cout << endl;

    cout << "Test 2: " << endl;
    String greeting("Hi");
    cout << "Before setContent: ";
    greeting.print();
    greeting.setContent("Hello");
    cout << "After setContent: ";
    greeting.print();
    greeting.append(" there");
    cout << "After append: ";
    greeting.print();
    cout << endl;

    cout << "Test 3: " << endl;
    String str1("Hi");
    String str2 = str1.clone();
    cout << "str1: ";
    str1.print();
    cout << "str2: ";
    str2.print();
    cout << "setContent str1: " << endl;
    str1.setContent("Hello");
    cout << "str1: ";
    str1.print();
    cout << "str2: ";
    str2.print();

}
