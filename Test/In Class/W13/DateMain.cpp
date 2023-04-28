#include <iostream>
#include <cstring>
#include <string>
#include <math.h>

#include "Date.h"
#include "Error.h"

using namespace std;

int main() {
	try {
		Date d1(24, 4, 2023);
		Date d2;
		Date d3(1,5,2023);
		
		//Q4
		cout << "Q4 - Test 1: ";
		if (strcmp(d1.toString(), "24/04/2023") != 0)
			throw Error("24/04/2023", d1.toString());
		cout << "OK" << endl;
		cout << "Q4 - Test 2: ";
		if (strcmp(d2.toString(), "00/00/0000") != 0)
			throw Error("00/00/0000", d2.toString());
		cout << "OK" << endl;
		cout << "Q4 - Test 3: ";
		if (strcmp(d3.toString(), "01/05/2023") != 0)
			throw Error("01/05/2023", d2.toString());
		cout << "OK" << endl;

		//Q5
		cout << "Q5 - Test 1: ";
		if (d1.getDay() != 24)
			throw Error(24, d1.getDay());
		cout << "OK" << endl;
		
		cout << "Q5 - Test 2: ";
		if (d1.getMonth() != 4)
			throw Error(4, d1.getMonth());
		cout << "OK" << endl;
		
		cout << "Q5 - Test 3: ";
		if (d1.getYear() != 2023)
			throw Error(2023, d1.getYear());
		cout << "OK" << endl;

		cout << "Q5 - Test 4: ";
		if (d2.getDay() != 0)
			throw Error(0, d2.getDay());
		cout << "OK" << endl;
		
		cout << "Q5 - Test 5: ";
		if (d2.getMonth() != 0)
			throw Error(0, d2.getMonth());
		cout << "OK" << endl;
		
		cout << "Q5 - Test 6: ";
		if (d2.getYear() != 0)
			throw Error(0, d2.getYear());
		cout << "OK" << endl;
        
		//Q6
		cout << "Q6 - Test 1: ";
		d2.setYear(2023);
		if (d2.getYear() != 2023)
			throw Error(2023, d2.getYear());
		cout << "OK" << endl;
		
		cout << "Q6 - Test 2: ";
		d2.setMonth(13);
		if (d2.getMonth() != 0)
			throw Error(0, d2.getMonth());
		cout << "OK" << endl;
		
		cout << "Q6 - Test 3: ";
		d2.setMonth(-1);
		if (d2.getMonth() != 0)
			throw Error(0, d2.getMonth());
		cout << "OK" << endl;
		
		cout << "Q6 - Test 4: ";
		d2.setMonth(2);
		if (d2.getMonth() != 2)
			throw Error(2, d2.getMonth());
		cout << "OK" << endl;

		cout << "Q6 - Test 5: ";
		d2.setDay(31);
		if (d2.getDay() != 0)
			throw Error(0, d2.getDay());
		cout << "OK" << endl;
		
		cout << "Q6 - Test 6: ";
		d2.setDay(-1);
		if (d2.getDay() != 0)
			throw Error(0, d2.getDay());
		cout << "OK" << endl;
		
		cout << "Q6 - Test 7: ";
		d2.setDay(26);
		if (d2.getDay() != 26)
			throw Error(26, d2.getDay());
		cout << "OK" << endl;
		//d1: 24/04/2023
		//d2: 26/02/2023
		//d3: 01/05/2023

		//Q7
		cout << "Q7 - Test 1: ";
		if (d1.compareTo(d2) != 1)
			throw Error(1, d1.compareTo(d2));
		cout << "OK" << endl;
		
		cout << "Q7 - Test 2: ";
		if (d1.compareTo(d3) != -1)
			throw Error(-1, d1.compareTo(d3));
		cout << "OK" << endl;
		
		cout << "Q7 - Test 3: ";
		if (d1.compareTo(d1) != 0)
			throw Error(0, d1.compareTo(d1));
		cout << "OK" << endl;

		//Extra
		const Date d4;
		d4.getDay();
		d4.getMonth();
		d4.getYear();
		d4.compareTo(d1);
		d1.compareTo(d4);

		cout << "Extra: OK";
	} catch(Error& e) {
		cout << e.getMessage() << endl;
	}
}
