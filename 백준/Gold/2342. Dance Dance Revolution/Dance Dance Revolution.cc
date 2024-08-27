#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

static long dp[100001][5][5];
int mp[5][5] = {
        {0,2,2,2,2},
        {2,1,3,4,3},
        {2,3,1,3,4},
        {2,4,3,1,3},
        {2,3,4,3,1}
};


int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = 0, s = 1;

        for (int i = 0; i < 5; i++) {
	for (int j = 0; j < 5; j++) {
	        for (int k = 0; k < 100001; k++) {
		dp[k][i][j] = 100001 * 4;
	        }
	}
        }
        dp[0][0][0] = 0;

        while (1) {
	cin >> n;
	if (n == 0) break;
	for (int i = 0; i < 5; i++) {
	        if (n == i) continue; // 두발이 제자리에 있을 수 없음.
	        for (int j = 0; j < 5; j++) {
		dp[s][i][n] = min(dp[s - 1][i][j] + mp[j][n], dp[s][i][n]);
	        }
	}
	for (int j = 0; j < 5; j++) {
	        if (n == j) continue; // 두발이 제자리에 있을 수 없음.
	        for (int i = 0; i < 5; i++) {
		dp[s][n][j] = min(dp[s - 1][i][j] + mp[i][n], dp[s][n][j]);
	        }
	}
	s++;
        }
        s--;
        long minVal =2100000000;
        for (int i = 0; i < 5; i++) {
	for (int j = 0; j < 5; j++) {
	        minVal = min(minVal, dp[s][i][j]);
	}
        }
        cout << minVal << endl;

        return 0;
}