#include <bits/stdc++.h>
typedef long long ll;
typedef long long int ll;
const unsigned int MOD = 1000000007;
#define lld long long int
using namespace std;

const int M=1e9+7;
ll mod(ll x){
    return ((x%M + M)%M);
}
ll add(ll a, ll b){
    return mod(mod(a)+mod(b));
}
ll mul(ll a, ll b){
    return mod(mod(a)*mod(b));
}

string convert(lld n) {
	string s = "";
	while (n > 0) {
		if (n % 2 == 1) s = "1" + s;
		else s = "0" + s;
		n /= 2;
	}
	return s;
}

lld convertBack(string s) {
	lld n = 0 , p = 1;
	for (lld i = s.length() - 1; i >= 0; i--) {
		n += ((s[i] - '0') * p);
		p *= 2;
	}
	return n;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        
        
    }
#ifndef ONLINE_JUDGE
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif
    return 0;
}