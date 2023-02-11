#include <bits/stdc++.h>
using namespace std;

int main()
{
  int arr[] = {2,3,3,2,5,6,2};
  unordered_map<int, int>ump;

  //inserting and travering techniques
  unordered_map<int, int>::iterator itr;
  ump.insert({2, 1});
  itr = ump.begin();
  cout << itr->first << " | " << itr->second << endl;
  for(auto i:arr){
    ump[arr[i]]++;
  }
  for(auto i:ump){
    cout << i.first << " " << i.second << endl;
  }
  return 0;
}