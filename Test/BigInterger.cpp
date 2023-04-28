#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

struct BigInteger{
    int sign;
    //string numberstring;
    char number[100];
    
};
typedef struct BigInteger BigInteger;
bool isFirstBigger(char *first, char *second);
int length(int first,int second);
void addZero(char* first , char* second);
BigInteger sum(BigInteger &first, BigInteger &second);
int main(){
    BigInteger first, second;
    cin >> first.sign >> first.number;
    cin >> second.sign >> second.number;
    BigInteger result = sum(first, second);
    if (result.sign == 0) {
        cout << "-";
    }
    cout << result.number;
    return 0;
}

int length(int first,int second){
    return (first >= second)? first : second;
}
char* addZeroFirst(char *first,int n){
    int length = strlen(first);
    char* result = new char[length + n];
    for(int i = strlen(first) - 1; i >= 0; i--){
        *(result + i + n) = *(first + i);
    }
    for(int i = 0; i < n;i++){
        *(result + i) = 0 + '0';
    }
    return result;
}
void addZero(char *first , char *second){
    if(strlen(first) < strlen(second)) strcpy(first,addZeroFirst(first,strlen(second)- strlen(first)));
    else if (strlen(first) > strlen(second)) strcpy(second,addZeroFirst(second,strlen(first) - strlen(second)));
}

bool isFirstBigger(char *first, char *second){
    bool check = true;
    int length = strlen(first);
    for(int i = 0; i < length; i++){
        if(first[i] > second[i]){
            break;
        }
        else if(first[i] < second[i]){
            check = false;
            break;
        } 
    }
    return check;
}

bool isSameSign(int first , int second){
    return (first == second)? true : false; 
}

vector<char> elimination(char *first, char *second){
    int lengthStr = length(strlen(first),strlen(second));
    vector<char>resultVec;
    int count = 0;

    for(int i = lengthStr - 1; i >= 0; i--){
        if((first[i] - '0') < (second[i] - '0')){
            int sumIndex = ((first[i] - '0') + 10) - (second[i] - '0') + count;
            count = -1;
            char h = (sumIndex) + '0';
            resultVec.push_back(h);
        }
        else{
            int sumIndex = (first[i] - '0') - (second[i] - '0') + count;
            if(sumIndex < 0){
                count = -1;
                sumIndex = 9;
            }
            else count = 0; 
            resultVec.push_back(sumIndex + '0');
        } 
    } 
    return resultVec;
}
BigInteger sum(BigInteger &first, BigInteger &second){
    
    BigInteger result;
    vector<char>resultVec;
    //add 0
    addZero(first.number,second.number);
    int lengthStr = length(strlen(first.number),strlen(second.number));
    //sign result
    if(isSameSign(first.sign , second.sign)){
        result.sign = first.sign;
        int count  = 0;
        for(int i = lengthStr - 1; i >= 0; i--){
            int sumIndex = ((first.number)[i] - '0') + ((second.number)[i] - '0') + count;
            if(sumIndex >= 10){
                count  = 1;
                char h = (sumIndex - 10) + '0';
                resultVec.push_back(h);
            } 
            else{       
                count = 0;
                resultVec.push_back(sumIndex + '0');
            }
        }
        if(count == 1) resultVec.push_back(1 + '0');
    }
    else{
        if(isFirstBigger(first.number,second.number)){
            result.sign = first.sign; 
            resultVec = elimination(first.number,second.number);
        } 
        else{
            result.sign = second.sign;
            resultVec = elimination(second.number,first.number);
        }      
    }
    
    int index = 0;
    for(auto it = resultVec.rbegin(); it != resultVec.rend(); it++){
        (result.number)[index] = *it;
        index++;
    }
    if((result.number)[0] - '0' == 0){
        int length = strlen(result.number);
        for(int i = 0; i < length; i++){
            (result.number)[i] = (result.number)[i + 1];
        }
    }
    return result;
}