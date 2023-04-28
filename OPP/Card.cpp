#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


void swap(int a, int b){
    int temp = a;
    a = b;
    b= temp;
}
class Card{
    private:
        string nameBook;
        string nameAuthor;
        int numberBook;
    public:
        Card(){

        }

        Card(string nameBook, string nameAuthor, int numberBook){
            this->nameBook = nameBook;
            this->nameAuthor = nameAuthor;
            this->numberBook = numberBook;
        }

        void display(){
            cout << "Name Book: " << nameBook << endl;
            cout << "Name Author: " << nameAuthor << endl;
            cout << "Number Book: " << numberBook << endl;    
        }
        int getNumBook(){
            return numberBook;
        }

        void sortCards(vector<Card> &cards){
            for(int i = 0; i < cards.size(); i++){
                for(int j = 0; j < cards.size() - i - 1; j++){
                    if(cards[i].getNumBook() > cards[i + 1].getNumBook()){
                        swap(cards[i],cards[i+1]);
                    }
                }
            }
        }
};