#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int>vi;
#define test ll tt; cin>>tt; while(tt--)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(i, b) for (ll i = 0; i < b; i++)
#define iterate(x) for(auto itr=x.begin(); itr != x.end(); ++itr)
#define printarr(a) for(auto i : a) cout<<i<<' ';cout<<endl;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define mod 1000000007
bool isPrime(ll n){if(n <= 1)return false;if(n <= 3)return true;if(n%2 == 0 || n%3 == 0)return false;for(ll i=5; i*i<=n; i=i+6)if(n%i == 0 || n%(i+2) == 0)return false;return true;}
ll nextPrime(ll N){if(N<=1)return 2;ll prime = N;bool found = false;while(!found){prime++;if(isPrime(prime))found=true;}return prime;}

/*
https://codeforces.com/problemset/problem/1144/F
6 5
1 5
2 1
1 4
3 1
6 1
output:
YES
10100
*/

// return false if graph is bipartile
bool dfs(int u, vector<bool>& visited, vector<bool>& col, vector<int> adj[]){
    visited[u] = true;
    for(auto v : adj[u]){
        if(visited[v] && col[u]==col[v]) 
            return false;
        else if(!visited[v]){
            col[v] = !col[u];
            if(!dfs(v, visited, col, adj)){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    IOS
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    int u, v;

    loop(i, m){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool>visited(n+1, false);
    vector<bool>color(n+1);
    color[1] = 1;

    if(dfs(1, visited, color, adj))
        cout << "YES\n";
    else
        cout << "NO\n";
    
    return 0;
}