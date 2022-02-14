#include <iostream>
#include <cmath>
using namespace std;
int z(int n,int x,int y){
    if(n == 0) return 0;

    int half = 1<<(n-1);
    if(x < half && y < half) return z(n-1,x,y);
    else if( x < half && y >= half) return half*half + z(n-1,x,y-half);
    else if( x >= half && y < half) return 2*half*half + z(n-1,x-half,y);
    else return 3*half*half + z(n-1,x-half,y-half);
}
int main(){
    int n,x,y;
    cin >> n >> x >> y;
    cout << z(n,x,y) << "\n";
    return 0;
}