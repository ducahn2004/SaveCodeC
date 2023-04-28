#include <iostream>
#include <cstring>
#include <string>

#include "Student.h"
#include "Date.h"
#include "Error.h"
using namespace std;



int main() {
	try {
		Student s1("Guzman", 12, 2, 2002, 1000);
		Student s2("Guillermo", 3, 8, 2002, 1001);	
		//Q5
		//  cout << "Q5: ";
		// if (strcmp(s1.toString(), "Guzman - 12/02/2002 - 1000 - 0/0/0") != 0)
		// 	throw Error("Guzman - 12/02/2002 - 1000 - 0/0/0", s1.toString());
		// cout << "OK" << endl;
		
		// //Q6
		
			cout << "Q6 - Test 1: ";
		char *s1Name01 = s1.getName();
		if (strcpy(s1Name01, "Guzman") == 0)
			throw Error("Guzman", s1.getName());
		cout << "OK" << endl;
		
		cout << "Q6 - Test 2: ";
		char *s1Name02 = s1.getName();
		if (s1Name01 == s1Name02)
			throw Error("Can tra ve mang xau ky tu moi!");
		cout << "OK" << endl;
		
		cout << "Q6 - Test 3: ";
		if (s1.getDateOfBirth().compareTo(Date(12, 2, 2002)) != 0)
			throw Error("12/02/2002", s1.getDateOfBirth().toString());
		cout << "OK" << endl;
		
		cout << "Q6 - Test 4: ";
		if (s1.getId() != 1000)
			throw Error(1000, s1.getId());
		cout << "OK" << endl;
		
		cout << "Q6 - Test 5: ";
		int *scoresArr1 = s1.getScores();
		if (scoresArr1[0] != 0 || scoresArr1[1] != 0 || scoresArr1[2] != 0) {
			char *message = new char[100];
			sprintf(message, "%d/%d/%d", scoresArr1[0], scoresArr1[1], scoresArr1[2]);
			throw Error("0/0/0", message);
		}
		cout << "OK" << endl;
		
		cout << "Q6 - Test 6: ";
		int *scoresArr2 = s1.getScores();
		if (scoresArr1 == scoresArr2)
			throw Error("Can tra ve mang moi!");
		cout << "OK" << endl;
	
		
		
		//Q7
		// cout << "Q7 - Test 1: ";
		// s1.setName("Luis");
		// if (strcmp(s1.getName(), "Luis") != 0)
		// 	throw Error("Luis", s1.getName());
		// cout << "OK" << endl;
		
		cout << "Q7 - Test 2: ";
		s1.setName("");
		if (strcmp(s1.getName(), "Guzman") != 0)
			throw Error("Guzman", s1.getName());
		cout << "OK" << endl;
			
		cout << "Q7 - Test 3: ";
		s1.setDateOfBirth(Date(1,1,2000));
		if (s1.getDateOfBirth().compareTo(Date(1,1,2000)) != 0)
			throw Error("01/01/2000", s1.getDateOfBirth().toString());
		cout << "OK" << endl;
		
		cout << "Q7 - Test 4: ";
		s1.setId(2000);
		if (s1.getId() != 2000)
			throw Error(2000, s1.getId());
		cout << "OK" << endl;
		
		cout << "Q7 - Test 5: ";
		s1.setId(-1);
		if (s1.getId() != 2000)
			throw Error(2000, s1.getId());
		cout << "OK" << endl;
		
		cout << "Q7 - Test 6: ";
		int* newScores = new int[3]{5,6,7};
		s1.setScores(newScores);
		if (s1.getScores()[0] != 5 || s1.getScores()[1] != 6 || s1.getScores()[2] != 7)
			throw Error("Mang scores khong co gia tri bang nhau");
		cout << "OK" << endl;
		
		cout << "Q7 - Test 7: ";
		newScores[0] = 6;
		if (s1.getScores()[0] != 5)
			throw Error("Can copy gia tri khong phai copy con tro");
		
		//Q8
		// Scores = [5, 6, 7]
		cout << "Q8 - Test 1: ";
		if (s1.getAttendance() != 5)
			throw Error(5, s1.getAttendance());
		cout << "OK" << endl;

		cout << "Q8 - Test 2: ";
		if (s1.getMidterm() != 6)
			throw Error(6, s1.getMidterm());
		cout << "OK" << endl;
		
		cout << "Q8 - Test 3: ";
		if (s1.getFinalterm() != 7)
			throw Error(7, s1.getFinalterm());
		cout << "OK" << endl;
		
		cout << "Q8 - Test 4: ";
		s1.setAttendance(6);
		if (s1.getAttendance() != 6)
			throw Error(6, s1.getAttendance());
		cout << "OK" << endl;
		
		// Scores = [6, 6, 7]
		cout << "Q8 - Test 5: ";
		s1.setAttendance(12);
		if (s1.getAttendance() != 6)
			throw Error(6, s1.getAttendance());
		cout << "OK" << endl;
		
		cout << "Q8 - Test 6: ";
		s1.setMidterm(7);
		if (s1.getMidterm() != 7)
			throw Error(7, s1.getMidterm());
		cout << "OK" << endl;
		
		// Scores = [6, 7, 7]
		cout << "Q8 - Test 7: ";
		s1.setMidterm(12);
		if (s1.getMidterm() != 7)
			throw Error(7, s1.getMidterm());
		cout << "OK" << endl;
		
		cout << "Q8 - Test 8: ";
		s1.setFinalterm(8);
		if (s1.getFinalterm() != 8)
			throw Error(8, s1.getFinalterm());
		cout << "OK" << endl;
		
		// Scores = [6, 7, 8]
		cout << "Q8 - Test 9: ";
		s1.setMidterm(12);
		if (s1.getFinalterm() != 8)
			throw Error(8, s1.getFinalterm());
		cout << "OK" << endl;	 
	} catch(Error& e) {
		cout << e.getMessage() << endl;
	}
}

