#include <iostream>
#include <string>
using namespace std;
int main(){
    string word = "abcd";
    //cin >> word;
    for(int i=0;i<=word.size();i++)
	{
		char x=word.back();
		word.pop_back();
		word.insert(word.begin()+0,x);
	}
    cout << word;
}