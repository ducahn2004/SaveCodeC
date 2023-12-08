#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(vector<int> arr) {
    vector<pair<int,int>> parr1;
    vector<pair<int,int>> parr2;
    for (long i = 0; i < arr.size(); i++)
        parr1.push_back({arr[i],i});    
    for (long i = 0; i < arr.size(); i++)
        parr2.push_back({arr[i],i});
    sort(parr1.begin(),parr1.end());
    sort(parr2.rbegin(),parr2.rend());
    int counta = 0; int countd = 0;  
    for (long i = 0; i < parr1.size(); i++) {
        while(i!=parr1[i].second){
            swap(parr1[i],parr1[parr1[i].second]);
            counta++;
        }
    }
    for (long i = 0; i < parr2.size(); i++) {
        while(i != parr2[i].second){
            swap(parr2[i],parr2[parr2[i].second]);
            countd++;
        }    
    }
    int result = 0;
    if (counta < countd) {
        result = counta;
    }
    else {
        result = countd;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
