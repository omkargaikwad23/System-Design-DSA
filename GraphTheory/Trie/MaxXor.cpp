#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
*/

class Node{
public:
    Node* children[2];
    bool containsBit(int bit){
        return (children[bit]!=NULL);
    }
    void put(int bit){
        children[bit] = new Node();
    }
    Node* get(int bit){
        return children[bit];
    }
};

class Solution {
    Node* root;
public:
    Solution(){
        root = new Node();
    }
    
    void insert(int num){
        int limit = 32;
        Node* curr = root;
        for(int i=31; i>=0; i--){
            int bit = num&(1<<i);
            if(bit!=0) bit = 1;
            
            if(!curr->containsBit(bit)){
                curr->put(bit);
            }
            curr = curr->get(bit);
        }
    }
    
    int searchComp(int num){
        Node* curr = root;
        int comp = 0;
        for(int i=31; i>=0; i--){
            int bit = num&(1<<i);
            if(bit!=0) bit = 1;
            
            if(curr->containsBit(!bit)){
                comp += (1<<i)*(!bit);
                curr = curr->get(!bit);
            } else {
                comp += (1<<i)*(bit);
                curr = curr->get(bit);
            }
        }
        return comp;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        Node* curr = root;
        for(int i=0; i<nums.size(); i++){
            insert(nums[i]);
        }
        
        int maxXor = 0;
        for(int i=0; i<nums.size(); i++){
            int comp = searchComp(nums[i]);
            //cout << nums[i] << " " << comp << "=" << (comp^nums[i]) << endl;
            maxXor = max(maxXor, comp^nums[i]);
        }
        return maxXor;
    }
};