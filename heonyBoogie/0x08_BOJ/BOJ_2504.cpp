#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    cin >> str;
    stack<char> s;
    int sum = 0;
    int num = 1;

    for(int i=0;i<str.size();i++){
        if(str[i] == '('){
            num*=2;
            s.push('(');
        }else if(str[i] == '['){
            num*=3;
            s.push('[');
        }else if(str[i] == ')'){
            if(s.empty() || s.top() != '('){
                cout << 0 <<"\n";
                return 0;
            }

            if(str[i-1] == '('){
                sum += num;
            }
            s.pop();
            num/=2;
        }else{
            if(s.empty() || s.top() != '['){
                cout << 0 <<"\n";
                return 0;
            }
            if(str[i-1] == '['){
                sum += num;
            }
            s.pop();
            num/=3;
        }
    }
    if(s.empty()) cout << sum << "\n";
    else cout << 0 << "\n";
    return 0;
}

