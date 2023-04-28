#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime>
#include <random>
using namespace std;

struct Date{
    int day;
    int month;
    int year;

    //constructor
    Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year){

    }
    Date() : Date(0,0,0){

    }

    int compareTo(const Date a){
        int h;
        if(year > a.year)h = 1;
        else if(year < a.year)h = -1;
        else{
            if(month > a.month)h = 1;
            else if(month< a.month)h = -1; 
            else{
                if(day > a.day)h = 1;
                else if(day< a.day)h = -1;
                else h = 0;
            }
        }
        return h;
    }
    string toString(){
        string result = "";
        (day < 10)? result += "0" + to_string(day) + "/" : result += to_string(day) + "/";
        (month < 10)? result += "0" + to_string(month) + "/" : result += to_string(month) + "/";
        result += to_string(year);
        return result;
    }
};
int ramdon(int min, int max){
    random_device rd;	// only used once to initialize (seed) engine
	mt19937 rng(rd());	// random-number engine used (Mersenne-Twister in this case)
    uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}
int main(){
    Date input(17,4,2023);

    std::cout << input.toString() << endl;

    Date *compare = new Date[10];

    Date input2(17,4,2023);
    for(int i = 0; i < 10; i++){
        compare[i] = Date(ramdon(1,28),ramdon(1,12),ramdon(1990,2030));
        cout << "Compare to Date: " << compare[i].toString() << " is " <<(input.compareTo(compare[i]) == 0? "equal" : (input.compareTo(compare[i]) == -1 )? "Smaller" : "Bigger") << endl; 
    }
    
    cout << "Compare to Date: " << input2.toString() << " is " <<(input.compareTo(input2) == 0? "equal" : (input.compareTo(input2) == -1 )? "Smaller" : "Bigger") << endl;
}

