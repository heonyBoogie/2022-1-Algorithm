#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){ 
    string a;
    stack<char> s;
    int ans=0;
    bool isRazer = false;
    cin >> a;
    for(auto c : a){
       if(s.empty() || s.top() == c){
           s.push(c);
           isRazer = true;
       }else{
           s.pop();
           if(isRazer){
                ans+=s.size();
                isRazer = false;
           }else{
               ans+=1;
           }
       }
    }
    cout << ans << "\n";
    return 0;
}