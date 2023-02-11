#include <bits/stdc++.h>
using namespace std;

// find max sum of subarray

int maxSumSubArray(int arr[], int n){
  int maxSum = INT_MIN;
  int curSum = 0;
  for(int i=0; i<n; i++){
    curSum += arr[i];
    maxSum = max(maxSum, curSum);
    if(curSum<0)  curSum = 0;
  }
  return maxSum;
}

int minSumSubArray(int arr[], int n){
  int minSum = INT_MAX;
  int curSum = 0;
  for(int i=0; i<n; i++){
    curSum += arr[i];
    minSum = min(minSum, curSum);
    if(curSum>0)  curSum = 0;
  }
  return minSum;
}


int main(){
  int n; cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>> arr[i];

  int res = maxSumSubArray(arr, n);
  // int res2 = minSumSubArray(arr, n);
  cout << res << endl;
  // cout << max(res, abs(res2)) << endl;
}