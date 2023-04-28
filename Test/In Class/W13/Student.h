#include <cstring>
#include <string>
#include "Date.h"
using namespace std;
#pragma once

class Student{

private:
    char* name;
    Date dateOfBirth;
    int id;
    double* scores;

public:
    // Constructor
    Student(const char* _name, const int day, const int month ,const int year, const int _id);
    Student(const char* _name, const Date&dob, const int _id);

    //setter
    void setName(string _name);
    void setName(const char* name);
    void setId(int _id);
    void setScores(double *_Scores);
    void setScores(int* _Scores);
    void setDateOfBirth(Date _dateOfBirth);
    void setAttendance(int _attend);
    void setMidterm(int _mid);
    void setFinalterm(int _Final);

    //getter
    char *getName();
    int* getScores();
    Date getDateOfBirth();
    int getId();
    int getAttendance();
    int getMidterm();
    int getFinalterm();
    
    char* toString();
    //5. Viết hàm toString() thực hiện việc trả về dữ liệu dưới định dạng 
    //“[name] – [dd/mm/yyy] – [id] – [scores[0]/scores[1]/scores[2]]” 
    //VD: “John – 23/02/2000 – 2545 – 4/5/7”.
    
    //Destructor
    ~Student();

};
