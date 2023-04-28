#include <iostream>
#include <cstring>
#include <string>
#include <math.h>

using namespace std;
#pragma once
class Error{
private:
    string message;

public:
    Error(string message);
    Error(string expected, string got);
    Error(int expected, int got);
    string getMessage();
};
