#include <iostream>
#include <string>
#include <string.h>
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

struct Student{
    char* name;
    Date dateOfBirth;
    int id;
    double *score;

    //Constructor
    Student(const char* _name,const int day,const int month,const int year,const int _id){
        name = new char[20];
        score = new double[3]();
        strcpy(name, _name);
        dateOfBirth = Date(day, month, year);
        id = _id;
    }
    Student(const char* _name, const Date&dob,const int _id){
        name = new char[20];
        score = new double[3]();
        strcpy(name, _name);
        dateOfBirth = dob;
        id = _id;
    }

    ~Student(){
        delete []name;
        delete []score;
    }
    void printInfor(){
        cout << "Name: ";
        int length = strlen(name);
        for(int i = 0; i < length; i++){
            cout << *(name + i);
        }
        cout << endl;
        cout << "ID: " << id << endl;
        cout <<"Date of Birth: " << dateOfBirth.toString() << endl;
        cout << "Score: " << *(score + 0) << "  " << *(score + 1) << "  " << *(score + 2) << endl;
    }

};
int ramdon(int min, int max){
    random_device rd;	// only used once to initialize (seed) engine
	mt19937 rng(rd());	// random-number engine used (Mersenne-Twister in this case)
    uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}
char** FamilyName = new char*[7];
char** FinalName = new char*[7];

int main(){
    for(int i = 0; i < 7; i++){
        FamilyName[i] = new char[11];
        FinalName[i] = new char [11];
    }
    strcpy(FamilyName[0],"Anderson ");
    strcpy(FamilyName[1],"Jackson ");
    strcpy(FamilyName[2],"Thomas ");
    strcpy(FamilyName[3],"Martin ");
    strcpy(FamilyName[4],"Hernandez ");
    strcpy(FamilyName[5],"Gonzalez ");
    strcpy(FamilyName[6],"Clark ");

    strcpy(FinalName[0],"James");
    strcpy(FinalName[1],"Robert");
    strcpy(FinalName[2],"John");
    strcpy(FinalName[3],"Michael");
    strcpy(FinalName[4],"William");
    strcpy(FinalName[5],"David");
    strcpy(FinalName[6],"Richard");

    for(int i = 0; i < 10; i++){
        char *StuName = new char[11];
        strcpy(StuName,FamilyName[ramdon(0,6)]);
        strncat(StuName, FinalName[ramdon(0,6)], strlen(FinalName[ramdon(0,6)]));
        Student student(StuName,ramdon(1,28),ramdon(1,12),ramdon(2000,2004),ramdon(22020000,22029999));
        (student.score)[0] = (double)ramdon(5,9) + (double)ramdon(0,99)/100;
        (student.score)[1] = (double)ramdon(5,9) + (double)ramdon(0,99)/100;
        (student.score)[2] = (double)ramdon(5,9) + (double)ramdon(0,99)/100;
        student.printInfor();
        delete[] StuName;
        cout << "=========================" << endl;
    }
    for(int i = 0; i < 7; i++){
        delete[] FamilyName[i];
        delete[] FinalName[i];
    }
    delete[] FinalName;
    delete[] FamilyName;


    // char *StuName1 = new char[20];
    // cin.getline(StuName1,20);
    // int day,month,year,id;
    // cin >> day >> month >> year >> id;

    // Student student(StuName1,day,month,year,id);

    // cin >> (student.score)[0];
    // cin >> (student.score)[1];
    // cin >> (student.score)[2];

    // student.printInfor();
    // delete[] StuName1;
    // student.cancel(student.name,student.score);

    
}
