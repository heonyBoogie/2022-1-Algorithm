#include <iostream>
#include <queue>
#include <string>
using namespace std;
int map[100][100];
int path[100][100] = { -1 };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
#define X first
#define Y second

int main() {
	int m, n, j = 0;
	string a;
	cin >> n >> m;

	for (int i = 0; i<n; i++) {
		cin >> a;
		for (char c : a) {
			if (c == '1') map[i][j++] = 1;
			else map[i][j++] = 0;
		}
		j = 0;
	}
	
	queue<pair<int, int>> Q;
	Q.push({ 0,0 });
	path[0][0] = 0;
	while (!Q.empty()) {
		pair<int, int> p1 = Q.front();
		Q.pop();
		for (int k = 0; k<4; k++) {
			int x = p1.X + dx[k];
			int y = p1.Y + dy[k];
			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (map[x][y] == 0 || path[x][y] > 0) continue;
			Q.push({ x,y });
			path[x][y] = path[p1.X][p1.Y] + 1;
		}
	}
	cout << path[n - 1][m - 1] +1 << "\n";
	return 0;
}