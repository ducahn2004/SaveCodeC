#include <iostream>

#include <vector>
#include <algorithm>
#include <string>
#include <utility>

#include <cstdlib> // for rand() and srand()
#include <ctime>
#include <random>
using namespace std;

class Student{

private:
    string name;
    int id;
    vector<int>scores{0,0,0};

public:
    //constructor
    Student(const string name, const int id, vector<int>scores){
        this->name = name;
        this->id = id;
        this->scores.swap(scores);
    }

    Student(const string name, const int id, const int regular,const int middle, const int final){
        this->name = name;
        this->id = id;
        // scores.push_back(regular);
        // scores.push_back(middle);
        // scores.push_back(final);
        scores[0] = regular;
        scores[1] = middle;
        scores[2]= final;
    }
    Student(){

    }

    //setter
    void setName(const string name){this->name = name;}
    void setId(const int id){this->id = id;}
    void setScores(const vector<int> scores){this->scores = scores;}
    void setRegular(const int regular){scores[0] = regular;}
    void setMiddle(const int middle){scores[1] = middle;}
    void setFinal(const int final){scores[2]= final;}

    //getter
    string getName()const{return name;}
    int getId()const {return id;}
    vector<int> getScores()const {return scores;}
    int getRegular() const {return scores[0];}
    int getMiddle() const {return scores[1];}
    int getFinal() const {return scores[2];}

    //member functio
    double getAverage(){
        double sum = 0;
        sum = 1.0*scores[0] + 1.0*scores[1]*3 + 1.0*scores[2]*6;
        return sum/10;
    }
    bool operator< (Student right){
        if(getAverage() < right.getAverage()) return true;
        else if(getAverage() > right.getAverage()) return false;
        else{
            return (id < right.id)? true:false;
        }
    }

    void printInfor(){
        cout << "Name: " << name << " " << "Id: " << id << " " << scores[0] << ":" << scores[1] << ":" <<scores[2] << " Average: " << getAverage() << endl;

    }
};

class UClass{

private:
    string nameSubject;
    string IdSubject;
    vector<Student>students;

public:
    UClass(const string nameSubject, const string IdSubject){
        this->nameSubject = nameSubject;
        this->IdSubject = IdSubject;
    }
    UClass(const string nameSubject, const string IdSubject, vector<Student>students):UClass(nameSubject,IdSubject){
        this->students = students;
    }

    //setter
    void setNameSubject(const string nameSubject){this->nameSubject = nameSubject;}
    void setIdSubject(const string IdSubject){this->IdSubject = IdSubject;}

    //getter
    string getNameSubject(){return nameSubject;}
    string getIdSubject(){return IdSubject;}

    //member func
    void addStudent(Student student){
        students.push_back(student);
    }
    
    void removeStudent(int id){
        for(int i = 0; i < students.size(); i++){
            if(students[i].getId() == id){
                students.erase(students.begin() + i);
                break;
            }
        }
    }

    Student getHighestScoreStudent(){
        int index = 0;
        double maxAverage = students[0].getAverage();
        for(int i = 1 ; i < students.size(); i++){
            if(students[i].getAverage() > maxAverage) index = i; 
        }
        return students[index];
    } 

    void print(){
        for(auto it : students){
            it.printInfor();
        }
    }

    void sortAsc(){
        sort(students.begin(),students.end(),[](Student &left, Student &right){return right < left;});
    }

    void sortDesc(){
        sort(students.begin(),students.end(),[](Student &left, Student &right){return left < right;});
    }
};


int ramdon(int min, int max){
    random_device rd;	// only used once to initialize (seed) engine
	mt19937 rng(rd());	// random-number engine used (Mersenne-Twister in this case)
    uniform_int_distribution<int> uni(min, max - 1);
    return uni(rng);
}

vector<string> FamilyName{"Anderson ","Jackson ","Thomas ","Martin ","Hernandez ","Gonzalez ","Clark "};
vector<string> FinalName{"James","Robert","John","Michael","William","David","Richard"};
vector<pair<string,string>> Subject{make_pair("MAT1042","Calculus 2"),make_pair("EPN1095","General Physics"),make_pair("ELT2035","Signals and systems"),make_pair("INT2210","Data structure and algorithms")};

int main(){
    

    int in = ramdon(0,Subject.size()-1);
    UClass classS(Subject[in].second,Subject[in].first);
    cout << "Name Subject : " << classS.getNameSubject() << endl << "ID Subject: " << classS.getIdSubject() << endl;
    for(int i = 0; i < 10; i++){
        Student studentInfor(FamilyName[0,ramdon(0,FamilyName.size())] + FinalName[0,ramdon(0,FinalName.size())],ramdon(22020000,22030000),ramdon(0,11),ramdon(0,11),ramdon(0,11));
        classS.addStudent(studentInfor);
    }

    cout << "Remove Student" << endl;
    Student studentInfor(FamilyName[0,ramdon(0,FamilyName.size())] + FinalName[0,ramdon(0,FinalName.size())],22031111,ramdon(0,11),ramdon(0,11),ramdon(0,11));
    classS.addStudent(studentInfor);
    cout << "before remove" << endl;
    classS.print();
    classS.removeStudent(22031111);
    cout << "after romove" << endl;
    classS.print();
    cout << endl;

    cout << "before sort" << endl;
    classS.print();
    cout << endl;
    classS.sortAsc();

    cout << "after sort Ascendse" << endl;
    classS.print();
    classS.sortDesc();
    cout << "after sort descendse" << endl;
    classS.print();

}