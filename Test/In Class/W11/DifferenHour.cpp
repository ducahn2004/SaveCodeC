#include <iostream>

using namespace std;

struct Time
{
    int hour, minute, second;
    Time(){

    }
    Time(int initHour, int initMinute, int initSecond)
    {
        hour = initHour;
        minute = initMinute;
        second = initSecond;
    }
    void getTimeDifference(Time other)
    {
        Time hourDef;
        int sum1 = hour * 3600 + minute * 60 + second;
        int sum2 = other.hour * 3600 + other.minute * 60 + other.second;
        int sum3 = abs(sum1 - sum2);
        hourDef.hour = sum3/3600;
        hourDef.minute = (sum3 - hourDef.hour * 3600)/60;
        hourDef.second = (sum3 - hourDef.hour * 3600 - hourDef.minute * 60);
        if(hourDef.hour < 10) cout << "0" << hourDef.hour << ":";
        else  cout << hourDef.hour << ":"; 
        if(hourDef.minute < 10) cout << "0" << hourDef.minute << ":";
        else  cout << hourDef.minute << ":"; 
        if(hourDef.second < 10) cout << "0" << hourDef.second;
        else  cout << hourDef.second; 
    }
};

int main()
{
    int hour, minute, second;
    cin >> hour >> minute >> second;
    Time time1(hour,minute,second);
    cin >> hour >> minute >> second;
    Time time2(hour,minute,second);
    time1.getTimeDifference(time2);
    return 0;
}
