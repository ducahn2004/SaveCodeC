#include <iostream>
#include <cstring>
#include <string>

#include "Date.h"
#include "Student.h"
#include "Convert.h"
//Constructor
Student::Student(const char* name,const int day,const int month,const int year,const int id){
	this->name = new char[20];
	scores = new double[3]();
	strcpy(this->name, name);
	*(this->name + strlen(name)) = '\0';
	dateOfBirth = Date(day, month, year);
	this->id = id;
}
Student::Student(const char* name, const Date&dob,const int id){
	this->name = new char[20];
	this->scores = new double[3]();
	strcpy(this->name, name);
	*(this->name + strlen(name)) = '\0';
	dateOfBirth = dob;
	this->id = id;
}

//setter 
void Student::setName(string name){
	if(!name.empty()){
		this->name = new char[20];
		for(int i = 0; i < name.size(); i++){
			*(this->name + i) = name[i];
		}
		*(this->name + name.size()) = '\0';
	}
	// else{
	// 	cout <<  "Name is invalid ";
	// }
}
void Student::setName(const char* name){
	if(strlen(name) != 0){
		this->name = new char[20];
		strcpy(this->name,name);
		*(this->name + strlen(name)) = '\0';
	}
	// else{
	// 	cout <<  "Name is invalid ";
	// }
} 
void Student::setId(int id){
	if(id > 0){
		this->id = id;
	}
	// else{
	// 	cout << "Id is invalid ";
	// }
}
void Student::setScores(double *scores){
	scores = new double[3];
	for(int i = 0; i < 3; i++){
		if( 0 <= *(scores + i) && *(scores + i) <= 10){*(this->scores + i) = *(scores + i);}
		else{
			break;
		}
	}
}
void Student::setScores(int *scores){
	this->scores = new double[3];
	for(int i = 0; i < 3; i++){
		if( 0 <= *(scores + i) && *(scores + i) <= 10){*(this->scores + i) = *(scores + i);}
		else{
			break;
		}
	}
}
void Student::setDateOfBirth(Date dateofBirth){
	this->dateOfBirth = dateofBirth;
}
void Student::setAttendance(int _attend){if(0 <= _attend && _attend <= 10) *(scores) = (double)_attend;}

void Student::setMidterm(int _mid){if(0 <= _mid && _mid <= 10) *(scores + 1) = (double)_mid;}

void Student::setFinalterm(int _Final){if(0 <= _Final && _Final <= 10) *(scores + 2) = (double)_Final;}
//getter
char* Student::getName(){
	char* temp = new char[20];
	*(temp + 19) = '\0';
	strcpy(temp,name);
	return temp;
}
int* Student::getScores(){
	int *temp = new int[3];
	*(temp) = *(scores);
	*(temp + 1) = *(scores + 1);
	*(temp + 2) = *(scores + 2);
	return temp;
}
Date Student::getDateOfBirth(){return dateOfBirth;}

int Student::getId(){
	return id;
}
int Student::getAttendance(){
	double temp = *(scores);
	int temp1 = (int)temp;
	return temp1;
}

int Student::getMidterm(){
	double temp = *(scores + 1);
	int temp1 = (int)temp;
	return temp1;
}

int Student::getFinalterm(){
	double temp = *(scores + 2);
	int temp1 = (int)temp;
	return temp1;
}

char * Student::toString(){
	char * result = new char [100];
	std::string temp = "";
	temp = convertString::cvName(name) + " - " + convertString::cvDateOfBirth(dateOfBirth) + " - " + convertString::cvId(id) + " - " + convertString::cvScores(Student::getScores());
	for(int i = 0; i < temp.size();i++){
		*(result + i) = temp[i];
	}
	*(result + temp.size()) = '\0';
	return result;
}

//destructor
Student::~Student(){
	delete []name;
	delete []scores;
}


