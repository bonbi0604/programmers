#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

int wb(int x, int y);
int bw(int x, int y);
vector<vector<char>>v;
int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n, m, answer = 100000000;
        cin >> n >> m;
        v.resize(n, vector<char>(m));
        for (int i = 0; i < n; i++) {//행
	for (int j = 0; j < m; j++) { //열
	        cin >> v[i][j];
	}
        }
        for (int i = 0; i <= n-8; i++) {
	for (int j = 0; j <= m-8; j++) {
	       answer = min(answer, bw(i, j));
	       answer = min(answer, wb(i, j));
	}
        }
        cout << answer << endl;
        return 0;
}

int wb(int x, int y) {
        int cnt = 0;
        for (int i = x; i < x + 8; i++) {
	for (int j = y; j < y + 8; j++) {
	        if ((i + j) % 2 == 0) {
		if (v[i][j] != 'W') cnt++;
	        }
	        else {
		if (v[i][j] != 'B') cnt++;
	        }
	}
        }
        return cnt;
}
int bw(int x, int y) {
        int cnt = 0;
        for (int i = x; i < x + 8; i++) {
	for (int j = y; j < y + 8; j++) {
	        if ((i + j) % 2 == 0) {
		if (v[i][j] != 'B') cnt++;
	        }
	        else {
		if (v[i][j] != 'W') cnt++;
	        }
	}
        }
        return cnt;
}