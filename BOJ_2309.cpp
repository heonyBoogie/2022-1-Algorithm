#include <iostream>
using namespace std;
int main(void){
	int a[9],x,y,sum,temp;
	
	for(int i=0;i<9;i++){
		cin >> a[i];
	}
	
	for(int i=0;i<9;i++){
		sum +=a[i];
	}
	
	int min_idx = 0;
	for(int i=0;i<9;i++){
		for(int j=i+1;j<9;j++){
			if(a[min_idx] > a[j]) min_idx = j;
		}
		temp = a[i];
		a[i] = a[min_idx];
		a[min_idx] = temp;
	}
	
	for(int i=0;i<9;i++){
		for(int j=i+1;j<9;j++){
			if((sum-(a[i]+a[j])) == 100) {
				x=i;
				y=j;
				break;
			}
		}
	}
	
	for(int i=0;i<9;i++){
		if(i==x || i==y) continue;
		cout << a[i] << "\n";
	}
	
	return 0;
}

