#include<iostream>
using namespace std;

class Animal{
    public:
        virtual void sound(){
            cout << "some sound" << endl;
        }
};

class Cat : public Animal{
    public:
        void sound(){
            cout << "meow meow" << endl;
        }
        void play(){
            cout << "here" << endl;
        }
};

class Dog : public Animal{
    public:
        void sound(){
            cout << "woof woof";
        }
        void play(){
            cout << "in the garden" << endl;
        }
};

int main(){
    //up casting 
    cout << "this is up-casting"<<endl;
    Cat cat1;
    Animal* animal1 = &cat1;
    animal1->sound();

    Dog dog1;
    Animal* animal2 = &dog1;
    animal2->sound();
    return 0;

    //down-casting
    Animal animal;
    Dog* dog2 = (Dog*)&animal;
    dog2->sound();
    dog2->play();
    return 0;
}