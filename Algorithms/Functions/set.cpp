#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int>vi;
#define test ll t; cin>>t; while(t--)
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(i, b) for (ll i = 0; i < b; i++)
#define iterate(x) for(auto itr=x.begin(); itr != x.end(); ++itr)
#define printarr(a) for(auto i : a) cout<<i<<' ';cout<<endl;


int main()
{
    int gfg[] = { 5, 6, 7, 7, 6, 5, 5, 6 };
 
    vector<int> v(gfg, gfg + 8); // 5 6 7 7 6 5 5 6
 
    sort(v.begin(), v.end()); // 5 5 5 6 6 6 7 7
 
    vector<int>::iterator lower, upper;
    lower = lower_bound(v.begin(), v.end(), 6);
    upper = upper_bound(v.begin(), v.end(), 6);
 
    // [
    cout << "lower_bound for 6 at position "
         << (lower - v.begin() + 1) << '\n';  //6
    // (
    cout << "upper_bound for 6 at position "
         << (upper - v.begin() + 1) << '\n';  //7
    
    
    return 0;
}