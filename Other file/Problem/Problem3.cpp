#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        stack<int>result;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
            if(result.empty()) result.push(*it);
            else if(*it != result.top()){
                result.push(*it);
            }
            else{
                nums.erase(it);
            }
        }
        return nums.size();
    }
};

int main(){
    Solution so;
    vector<int>nums{0,0,1,1,1,2,2,3,3,4};
    cout << so.removeDuplicates(nums) << endl;
    for(auto it : nums){
        cout << it << " "; 
    }
}
// expect
// 5
// 0 1 2 3 4
