#include <bits/stdc++.h>
using namespace std;

//maximum reactangular area histogram area
int maxHistogram(int arr[], int n){
  stack<int>s;
  s.push(arr[0]);
  int maxArea = -1;
  
  int i = 0;
  while(i<n){
    int tempArea = 0;
    if(s.top() <= arr[i]){
      s.push(arr[i]);
      i++;
    }
    else{
      while(s.empty() && arr[i]>arr[i]){
        int temp = s.top();
        if(s.empty()){
          maxArea = max(maxArea, temp*i);
        }else{
          maxArea = max(maxArea, temp*(i-s.top()-1));
        }
      }
      
      s.push(arr[i]);
    }

    // if(tempArea>maxArea){
    //   maxArea = tempArea;
    // }
  }
  return maxArea;
  
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  int ans = maxHistogram(arr, n);
  cout << ans ;
  return 0;
}