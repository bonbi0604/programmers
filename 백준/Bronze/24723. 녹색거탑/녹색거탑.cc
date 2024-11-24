#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <queue>
#include <numeric>
using namespace std;


int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n, answer = 0;
        cin >> n;

        vector<vector<int>>v(n+1, vector<int>(n+1,0));
        for (int i = 0; i <= n; i++) {
	v[i][0] = 1;
	v[i][i] = 1;
        }

        for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= n; j++) {
	        if (i <= j) continue;
	        v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
	}
        }
        answer = accumulate(v[n].begin(), v[n].end(), 0);
        cout << answer << endl;
        return 0;
}
