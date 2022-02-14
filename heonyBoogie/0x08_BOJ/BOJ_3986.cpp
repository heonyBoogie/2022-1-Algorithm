#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int n,ans = 0;
    cin >> n;
    while(n--){
        string a;
        stack<char> s;
        cin >> a;

        for(auto c : a){
            if(s.empty() || s.top() != c){
                s.push(c);
            }else{
                s.pop();
            }
        }
        if(s.empty()) ans++;
    }
    cout << ans << "\n";
    return 0;
}