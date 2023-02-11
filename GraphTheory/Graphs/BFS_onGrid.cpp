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

/*
3 5
S###.
.....
###E#

OUTPUT: 5
Steps required to reach from 'S' to 'E'?
*/

// https://open.kattis.com/problems/dungeon
typedef vector<vector<char>> vvch;

int shortest_path(vvch path, pii src, int r, int c){
    // variables to keep track of no of steps taken
    bool reached_end = false;
    int move_count = 0, nodes_left_in_layer = 1, nodes_in_next_layer = 0;
    
    // to keep track of visited cells
    bool visited[r][c];
    memset(visited, false, sizeof(visited));
    
    // define 4 vector directions to move
    vector<pii>dir_vect = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    queue<pii>q;
    q.push({src.first, src.second});

    while(!q.empty()){
        int ri = q.front().first, ci = q.front().second;
        q.pop();

        if(path[ri][ci]=='E'){
            reached_end = true;
            break;
        }

        // exploring neighbours
        for(auto dir : dir_vect){
            int new_r = ri + dir.first;
            int new_c = ci + dir.second;

            // skip out of bounds locations
            if(new_r<0 || new_c<0) continue;
            if(new_r>=r || new_c>=c) continue;

            // skip visited or blocked locations
            if(visited[new_r][new_c]) continue;
            if(path[new_r][new_c] == '#') continue;

            q.push({new_r, new_c});
            visited[new_r][new_c] = true;
            nodes_in_next_layer++;
        }
        // think, dryrun you will get it
        nodes_left_in_layer--;
        if(nodes_left_in_layer==0){
            nodes_left_in_layer = nodes_in_next_layer;
            nodes_in_next_layer = 0;
            move_count++;
        }
    }
    if(reached_end)
        return move_count;
    return -1;
}

int main()
{
    IOS
    int l, r, c; cin >> r >> c;
    vvch path;
    pii src;
    for(int i=0; i<r; i++){
        vector<char>row;
        for(int j=0; j<c; j++){
            char ch; cin >> ch;
            if(ch=='S')
                src.first = i, src.second = j;
            
            row.push_back(ch);
        }
        path.push_back(row);
    }

    int length = shortest_path(path, src, r, c);
    
    if(length<0){
        cout << "Trapped!";
    }
    else{
        cout << "Escaped in " << length << " minute(s).";
    }
    return 0;
}