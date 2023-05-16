#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Student{

private:
    string name;
    int id;
    vector<int>scores;

public:
    //constructor
    Student(const string name, const int id, vector<int>scores){
        this->name = name;
        this->id = id;
        this->scores = scores;
    }

    Student(const string name, const int id, const int regular,const int middle, const int final){
        this->name = name;
        this->id = id;
        scores[0] = regular;
        scores[1] = middle;
        scores[2] = final;
    }
    Student(){

    }

    //setter
    void setName(const string name){this->name = name;}
    void setId(const int id){this->id = id;}
    void setScores(const vector<int> scores){this->scores = scores;}
    void setRegular(const int Regular){scores[0] = Regular;}
    void setMiddle(const int middle){scores[1] = middle;}
    void setFinal(const int final){scores[2]= final;}

    //getter
    string getName()const{return name;}
    int getId()const {return id;}
    vector<int> getScores()const {return scores};
    int getRegular() const {return scores[0]};
    int getMiddle() const {return scores[1]};
    int getFinal() const {return scores[2]};

    //member functio
    double getAverage(vector<int> arr){
        double sum = 0;
        for(auto it : arr){
            sum += 1.0*it;
        }
        return sum/3;
    }
    bool operator< (Student right){
        if(getAverage(scores) > getAverage(right.scores)) return true;
        else if(getAverage(scores) > getAverage(right.scores)) return false;
        else{
            return (id < right.id)? true:false;
        }
    }

    void printInfor(){
        cout << "Name: " << name << " " << "Id: " << id << " " << scores[0] << ":" << scores[1] << ":" <<scores[2] << endl;

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
        for(int i = 0; i < students.szie(); i++){
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
        return students[i];
    } 

    void print(){
        for(auto it : students){
            it.printInfor();
        }
    }

    void sortAsc(){
        sort(students.begin(),students.end(),[](Student left, Student right){return right < left});
    }
    
    void sortDesc(){
        sort(students.begin(),students.end(),[](Student left, Student right){return left < right});
    }
};

int main(){

}