#include <iostream>
using namespace std;
bool isUsed[9]; //인덱스 1~8까지 사용
int arr[8]; 
int n,m;
void func(int k){
    if(k==m){
        for(int i=0;i<m;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return ;
    }else{
        for(int i=1;i<=n;i++){
            if(!isUsed[i]){
                if(k > 0 && arr[k-1] < i ){
                    arr[k] = i;
                    isUsed[i] = true;
                    func(k+1);
                    isUsed[i] = false;
                }else if(k == 0){
                    arr[k] = i;
                    isUsed[i] = true;
                    func(k+1);
                    isUsed[i] = false;
                }
            }
        }
    }

}
int main(){
    cin >> n >> m;
    func(0);
    return 0;
}