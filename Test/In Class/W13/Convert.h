#include <string>
#include "Date.h"

namespace convertString{
    
    std::string cvName(char* name);

    std::string cvDateOfBirth(Date _dateOfBirth);

    std::string cvId(int _id);

    std::string cvScores(double* _scores);

    std::string cvScores(int* _scores);


} // namespace convertString
