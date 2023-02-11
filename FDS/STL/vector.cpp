#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int>v1;
  v1.push_back(10);
  v1.push_back(20);
  v1.push_back(30);

  vector<int>::iterator itr;
  for(itr=v1.begin(); itr!=v1.end();++itr){
    cout << *itr << " ";
  }
  cout << endl;
  cout << " size() = " << v1.size() << endl;
  cout << " at(1) = " << v1.at(1) << endl;
  cout << " back() = " << v1.back() << endl;  //gives a reference to the last element.
  cout << " front() = " << v1.front() << endl;
  cout << " min_element() = " << *min_element(v1.begin(), v1.end()) << endl;
  cout << " max_element() = " << *max_element(v1.begin(), v1.end()) << endl;

  int *k = v1.data();  //returns a pointer to an array internally used by a vector to store its elements.
  cout << " data() " << *k << endl;
  vector<int>v2{110, 220, 330};
  v2.assign(v1.begin(),v1.end()-1);
  for(int i=0;i<v2.size();i++)
    cout<<v2[i] << " ";

}