#include <iostream>
#include <queue>
using namespace std;
int paper[500][500];
bool vis[500][500] = {false};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
#define X first
#define Y second

int main(){
    int m,n;
    int num = 0, max =0;
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> paper[i][j];
        }
    }
    queue<pair<int,int>> Q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(paper[i][j] == 1 && !vis[i][j]){
                Q.push({i,j});
                vis[i][j] = true;
                int size = 1;
                num++;
                while(!Q.empty()){
                    pair<int,int> p1 = Q.front();
                    Q.pop();
                    for(int k=0;k<4;k++){
                        int x = p1.X + dx[k];
                        int y = p1.Y + dy[k];
                        if(x < 0 || x >= n || y < 0 || y >= m) continue;
                        if(paper[x][y] == 1 && !vis[x][y]) {
                            Q.push({x,y});
                            vis[x][y] = true;
                            size++;
                        }
                    }
                }
                if(size > max) max = size;
            }
        }
    }
    cout << num << "\n" << max << "\n";
    return 0;
}   