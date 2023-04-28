#include "Convert.h"
#include <string>
#include <cstring>


std::string convertString::cvName(char* name){
    std::string result = "";
    result.append(name);
    return result;
}

std::string convertString::cvId(int _id){
    std::string result = "";
    result.append(std::to_string(_id));
    return result;

}

std::string convertString::cvDateOfBirth(Date _dateOfBirth){
    std::string result = "";
    (_dateOfBirth.getDay()< 10)? result += "0" + std::to_string(_dateOfBirth.getDay()) + "/" : result += std::to_string(_dateOfBirth.getDay()) + "/";
    (_dateOfBirth.getMonth() < 10)? result += "0" + std::to_string(_dateOfBirth.getMonth()) + "/" : result += std::to_string(_dateOfBirth.getMonth()) + "/";
    result += std::to_string(_dateOfBirth.getYear());
    return result;
}

std::string convertString::cvScores(double* _scores){
    std::string result = "";
    for(int i = 0; i < 3; i++){
        result += std::to_string(*(_scores + i));
        result += '/';
    }
    result.erase(result.end() - 1);
    return result;
}

std::string convertString::cvScores(int* _scores){
    std::string result = "";
    for(int i = 0; i < 3; i++){
        result += std::to_string(*(_scores + i));
        result += '/';
    }
    result.erase(result.end() - 1);
    return result;
}