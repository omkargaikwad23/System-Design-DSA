#include <bits/stdc++.h>
using namespace std;

/*
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

*/

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> ans(n, -1);
    
    for(int i=n-1; i>=0; i--) 
        stk.push(i);
    
    for(int i=n-1; i>=0; i--){
        while(!stk.empty() && nums[stk.top()] <= nums[i]){
            stk.pop();
        }
        if(!stk.empty()){
            ans[i] = nums[stk.top()];
        }
        stk.push(i);
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<int> nums = {1,2,3,4,3};
    vector<int> ans = nextGreaterElements(nums);
    return 0;
}