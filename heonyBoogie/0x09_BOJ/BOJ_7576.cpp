#include <iostream>
#include <queue>

using namespace std;
int map[1000][1000];
int vis[1000][1000] = { 0 };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
#define X first
#define Y second

int main() {
	int m, n;
	cin >> n >> m;
	queue<pair<int, int>> Q;
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				Q.push({ i,j });
			}
			if (map[i][j] == 0) {
				vis[i][j] = -1;
			}
		}
	}

	while (!Q.empty()) {
		pair<int, int> p1 = Q.front();
		Q.pop();
		for (int k = 0; k<4; k++) {
			int x = p1.X + dx[k];
			int y = p1.Y + dy[k];
			if (x < 0 || x >= m || y < 0 || y >= n) continue;
			if (vis[x][y] >= 0) continue;
			vis[x][y] = vis[p1.X][p1.Y] + 1;
			Q.push({ x,y });
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == -1) {
				cout << -1 << "\n";
				return 0;
			}
			ans = max(ans, vis[i][j]);
		}
	}
	cout << ans << "\n";
	return 0;
}