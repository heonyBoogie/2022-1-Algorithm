#include <iostream>
using namespace std;
int main(void){
	int a,b,c;
	cin >> a >> b >> c;
	int m = a*b*c;
	int arr[10] = {};
	
	while(m>0){
		arr[m%10]++;
		m/=10;
	}
	for(int i=0;i<10;i++){
		cout << arr[i] << "\n";
	} 
	return 0;
}
