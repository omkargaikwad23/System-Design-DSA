#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
#define minArr(a)  *min_element(arr(a))
#define minVec(a)  *min_element(vec(a))
#define maxArr(a)  *max_element(arr(a))
#define maxVec(a)  *max_element(vec(a))
#define pii pair<int, int>
#define loop(i, a, b) for (int i = a; i < b; i++)

int main()
{
  string h1, temp;
  getline(cin, h1);
  string txt;
  getline(cin, txt);

  stringstream X(h1);
  stringstream Y(txt);

  map<char, int>mp1;
  map<char, int>mp2;

  while(getline(X, temp, ' ')){
    loop(i, 0, temp.length()){
      mp1[temp[i]]++;
    }
  }
  while(getline(Y, temp, ' ')){
    loop(i, 0, temp.length()){
      mp2[temp[i]]++;
    }
  }
  bool flag = true;
  map<char, int>::iterator itr;
  for(auto i: mp2){
    itr = mp1.find(i.first);
    //cout << itr->first << " " << i.first << endl;
    if(itr->second < i.second || itr == mp1.end()){
      flag = false;
    }
  }
  if(flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  
  return 0;
}