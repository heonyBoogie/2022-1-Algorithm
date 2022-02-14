#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

char deploy[5][5];
bool mark[5][5];
int ans = 0,cnt =0,size=0; // cnt는 Y를 칠공주에 넣은 횟수
stack<pair<int,int>> st;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main(){
    for(int i=0;i<5;i++){
        string s;
        cin >> s;
        for(int j=0;j<5;j++){
            deploy[i][j] = s[j];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(deploy[i][j] == 'Y') cnt++;
            mark[i][j] = true;
            st.push({i,j}); 
            size++;
            while(!st.empty() && size < 7){
                auto p1 = st.top();
                st.pop();
                for(int k=0;k<4;k++){
                    int nx = p1.first + dx[k];
                    int ny = p1.second + dy[k];
                    if(nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
                    if(mark[nx][ny]) continue;
                    if(deploy[nx][ny] == 'Y'){
                        if(cnt < 3){
                            mark[nx][ny] = true;
                            size++;
                            cnt++;
                            st.push({nx,ny});
                        }
                    }else{
                        mark[nx][ny] = true;
                        size++;
                        st.push({nx,ny});
                    }
                }
            }
            while(!st.empty()) st.pop();
            if(size == 7) ans++;
            size = 0;
            cnt = 0;
            for(int i=0;i<5;i++){
                fill(mark[i],mark[i]+5,false);
            }
        }
    }
   
    cout << ans << "\n";
    return 0;
}