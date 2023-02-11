#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>vi;
typedef vector<ll>vl;
typedef vector<bool>vb;
#define test ll tt; cin>>tt; while(tt--)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(i, b) for (ll i = 0; i < b; i++)
#define printarr(a) for(auto i:a) cout<<i<<' ';cout<<endl;
#define all(x) (x).begin(), (x).end()
#define mod 1000000007

void solve(){

}


int main()
{
    string str1 = "sushant";
    cout << str1 << "\n";
    cout << str1.size() << "\n";
    cout << str1.find("us") << "\n";
    cout << str1.substr(0, 4) << "\n"; // PAR: (index, no of charaters)
    reverse(str1.begin(), str1.end());
    cout << "rev: " << str1 << endl;
    str1.push_back('A');
    cout << str1 << endl;
    cout << str1.back() << endl;
    str1.pop_back();
    cout << str1 << endl;

    cout << "\n";
    string strnum = to_string(100);
    double num = 100;
    cout << typeid(strnum).name() << endl;
    string str2 = "100";
    int strnum2 = stoi(str2);
    cout << strnum2 - 10 << endl;
    cout << typeid(strnum2).name() << endl;
    
    cout << ('9'-'0') << endl;
    cout << (char)('B'+32) << endl;
    cout << (char)('c'-32) << endl;

    cout << tolower('A') << endl;
    
    return 0;
}