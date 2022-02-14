#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
char maze[1000][1000];
int j_time[1000][1000];
int f_time[1000][1000];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
#define X first
#define Y second
using namespace std;

int main() {
	int r, c;
	cin >> r >> c;
	queue<pair<int, int>> QJ;
	queue<pair<int, int>> QF;
	for (int i = 0; i < r; i++) {
		fill(j_time[i], j_time[i] + c, -1);
		fill(f_time[i], f_time[i] + c, -1);
	}
	for (int i = 0; i<r; i++) {
		string a;
		cin >> a;
		for (int j = 0; j<c; j++) {
			maze[i][j] = a[j];
			if (maze[i][j] == 'J') {
				QJ.push({ i,j });
				j_time[i][j] = 0;
			}
			if (maze[i][j] == 'F') {
				QF.push({ i,j });
				f_time[i][j] = 0;
			}
		}
	}
	while (!QF.empty()) {
		auto p1 = QF.front();
		QF.pop();
		for (int i = 0; i<4; i++) {
			int nx = p1.X + dx[i];
			int ny = p1.Y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (maze[nx][ny] == '#' || f_time[nx][ny] >= 0) continue;
			QF.push({ nx,ny });
			f_time[nx][ny] = f_time[p1.X][p1.Y] + 1;
		}
	}

	while (!QJ.empty()) {
		auto p1 = QJ.front();
		QJ.pop();
		for (int i = 0; i<4; i++) {
			int nx = p1.X + dx[i];
			int ny = p1.Y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << j_time[p1.X][p1.Y] + 1;
				return 0;
			}
			if (maze[nx][ny] == '#' || j_time[nx][ny] >= 0) continue;
			if (f_time[nx][ny] != -1 && f_time[nx][ny] <= j_time[p1.X][p1.Y] + 1) continue;
			QJ.push({ nx,ny });
			j_time[nx][ny] = j_time[p1.X][p1.Y] + 1;
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
