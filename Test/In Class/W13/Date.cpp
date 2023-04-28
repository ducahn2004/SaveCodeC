#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include "Date.h"
using namespace std;
  
Date::Date(int _day, int _month, int _year): day(_day),month(_month),year(_year){

}
Date::Date(): Date(0,0,0){

}

// setter
void Date::setDay(int day){
    if(1 <= day && day <= 30){
        this->day = day;
    }
    // else{
    //     cout << "Day is invalid ";
    // }
    
}
void Date::setMonth(int month){
    if(1 <= month && month <= 12){
        this->month = month;
    }
    // else{
    //     cout << "Month is invalid ";
    // }
}
void Date::setYear(int year){ this->year = year; }

//getter
int Date::getDay()const { return day; }
int Date::getMonth()const { return month; }
int Date::getYear()const { return year; }


char* Date::toString(){
    char* result = new char[11];
    *(result + 10) = '\0';

    if(day < 10){
        *(result) = '0';
        *(result + 1) = day + '0';
    }
    else{
        *(result) = day/10 + '0';
        *(result + 1) = day%10 + '0';
    }
    *(result + 2) = '/';
    if(month < 10){
        *(result + 3) = '0';
        *(result + 4) = month + '0';
    }
    else{
        *(result + 3) = month/10 + '0';
        *(result + 4) = month%10 + '0';
    }
    *(result + 5) = '/';
    int i = 0;
    int year_copy = year;
    while(i < 4){
        *(result + 9  - i) = year_copy % 10 + '0';
        year_copy = (year_copy - year_copy%10)/10; 
        i++; 
    }
    return result;
}
int Date::compareTo(const Date a) const{
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

