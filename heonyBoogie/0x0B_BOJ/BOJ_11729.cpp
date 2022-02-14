#include <iostream>
#include <queue>
using namespace std;
queue<pair<int,int>> Q;
void hanoi(int n,int t1,int t2){ // t1 ,t2 는 tower 이름
    if(n==1) {
        Q.push({t1,t2});
        return;
    }
    else{
        hanoi(n-1,t1,6-t1-t2);
        Q.push({t1,t2});
        hanoi(n-1,6-t1-t2,t2);
    } 
}
int main(){
    int n;
    cin >> n;
    hanoi(n,1,3);
    cout << Q.size() << "\n";
    while(!Q.empty()){
        auto t = Q.front();
        cout << t.first << " " << t.second << "\n";
        Q.pop();
    }
    return 0;
}