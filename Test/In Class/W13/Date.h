#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#pragma once
class Date{
private:
    int day;
    int month;
    int year;

public:
    Date(int _day,int _month, int _year);

    Date();

    //setter
    void setDay(int _day);
    void setMonth(int _month);
    void setYear(int _year);

    //getter
    int getDay()const;
    int getMonth()const;
    int getYear()const;

    char* toString();
    int compareTo(const Date a)const;
    
};