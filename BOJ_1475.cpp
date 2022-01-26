#include <iostream>
using namespace std;
int main(void){
	int num;
	cin >> num;
	int arr[10] = {};
	
	while(num>0){
		if(num%10 == 9) {
			arr[6]++;
			num/=10;
			continue;
		}
		arr[num%10]++;
		num/=10;
	}
	
	arr[6] = arr[6]%2 + arr[6]/2
	
	int max = 0;
	for(int i=1;i<10;i++){
		if(arr[i] > arr[max]) max = i;
	}
	
	cout << arr[max];
	return 0;
}
