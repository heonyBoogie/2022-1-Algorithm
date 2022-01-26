#include <iostream>
using namespace std;
int main(void){
	int n,x,cnt = 0;
	cin >> n;
	int freq[100001] = {};
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	cin >> x;
	
	for(int i=0;i<n;i++){
		//freq[arr[i]]=1;
		if(x-arr[i] <= 100000 && x-arr[i] >= 1 && freq[x-arr[i]] == 1) cnt++;
		freq[arr[i]]=1;
	}
	
	cout << cnt;
	
	return 0;
}

/*
16line if문 앞에 있을 경우 아래 test를 실행하면 잘못 count함. 
9
5 12 7 10 9 1 2 3 11
10 

*/
 
