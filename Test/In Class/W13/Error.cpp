#include <cstring>
#include <string>
#include "Error.h"
using namespace std;

Error::Error(string message) {
	this->message= message;
}
Error::Error(string expected, string got) {
	this->message = "Expected: " + expected + " but got " + got;
}
Error::Error(int expected, int got) : Error(to_string(expected), to_string(got)) {}
string Error::getMessage(){
	return message;
}
