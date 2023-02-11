#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int parenti, parentj;
    double f, g, h; // f = g + h
};

class A_Star {
    int R = 5, C = 5;
    vector<vector<char>> path;
    pair<int, int> src, dest;
public:
    A_Star(){}
    A_Star(vector<vector<char>>& path){
        this->path = path;
        src = {0,0};
        dest = {4,2};
    }

    void printPath(){
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++)
                cout << path[i][j] << " ";
            cout << endl;
        }
    }

    void tracePath(vector<vector<Cell>>& cellInfo){
        int x = dest.first, y = dest.second;
        while(!(cellInfo[x][y].parenti == -1 && cellInfo[x][y].parentj == -1)){
            path[x][y] = '$';
            int tempx = cellInfo[x][y].parenti;
            int tempy = cellInfo[x][y].parentj;
            x = tempx, y = tempy;
        }
        path[src.first][src.second] = '$';
    }

    void A_StarSearch(){
        bool closeList[R][C];
        memset(closeList, false, sizeof(closeList));
        using pdii = pair<double, pair<int, int>>;
        priority_queue<pdii, vector<pdii>, greater<pdii>> openList; // <f,<i,j>> 
        
        vector<vector<Cell>> cellInfo(R, vector<Cell>(C));
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cellInfo[i][j].f = FLT_MAX;
                cellInfo[i][j].g = FLT_MAX;
                cellInfo[i][j].h = FLT_MAX;
                cellInfo[i][j].parenti = -1;
                cellInfo[i][j].parentj = -1;
            }
        }

        cellInfo[src.first][src.second].f = 0.0;
        cellInfo[src.first][src.second].g = 0.0;
        cellInfo[src.first][src.second].h = 0.0;

        vector<pair<int, int>> dir = {{0, 1},{1,0},{-1,0},{0,-1}};
        openList.push({0.0, {src.first, src.second}});
        bool foundDest = false;

        while(!openList.empty()){
            pdii p = openList.top();
            openList.pop();
            int curi = p.second.first;
            int curj = p.second.second;
            closeList[curi][curj] = true;
            if(curi==dest.first && curj==dest.second){ 
                foundDest = true; break;
            }
    
            for(auto& d : dir){
                int newi = curi + d.first;
                int newj = curj + d.second;
                if(newi<0 || newj<0 || newi>=R || newj>=C) continue;
                if(path[newi][newj] == '*' || closeList[newi][newj]) continue;

                int gNew = cellInfo[curi][curj].g + 1.0;
                int hNew = (double)sqrt(pow(newi-dest.first, 2) + pow(newj-dest.second, 2));
                int fNew = gNew + hNew;

                if(cellInfo[newi][newj].f > fNew){
                    openList.push({fNew, {newi, newj}});
                    cellInfo[newi][newj].g = gNew;
                    cellInfo[newi][newj].h = hNew;
                    cellInfo[newi][newj].f = fNew;
                    cellInfo[newi][newj].parenti = curi;
                    cellInfo[newi][newj].parentj = curj;
                }
            }
        }
        if(foundDest){
            tracePath(cellInfo);
            cout << "Found my destiny!!\n";
            printPath();
        }else{
            cout << "Cannot reach destiny!!\n";
        }
    }
};

int main(){
    vector<vector<char>> path = {{'.','.','.','.','.'},{'.','.','.','.','.'},{'.','.','.','.','.'},{'*','*','*','*','.'},{'.','.','.','.','.'}};
    A_Star astar(path);
    astar.A_StarSearch();
}