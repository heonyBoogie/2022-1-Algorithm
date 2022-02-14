#include <iostream>
using namespace std;
short arr[2187][2187];
int a = 0, b = 0, c = 0;
int func(int n, short x, short y) {
	short t = arr[x][y];
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			if (t != arr[x + i][y + j]) {
				int d = n / 3;
				func(d, x, y);
				func(d, x, y+d);
				func(d, x, y+d * 2);
				func(d, x+d, y);
				func(d, x+d, y+d);
				func(d, x+d, y+d * 2);
				func(d, x+d * 2, y);
				func(d, x+d * 2, y+d);
				func(d, x+d * 2, y+d * 2);
				return 0;
			}
		}
	}
	if (t == -1) a++;
	if (t == 0) b++;
	if (t == 1) c++;
	return 0;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cin >> arr[i][j];
		}
	}
	func(n, 0, 0);

	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";

	return 0;
}