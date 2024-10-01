#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<vector<int>>v;
vector<vector<int>>sum;
void recursive(int cnt, int pos);


int main() {
       cin >> n;
       v.resize(n, vector<int>(3));
       sum.resize(n, vector<int>(3));
       

        for (int i = 0; i < n; i++) {
	for (int j = 0; j < 3; j++) {
	        cin >> v[i][j];
	}
        }

        recursive(0, -1);
  
        cout << *min_element(sum[n-1].begin(), sum[n-1].end()) << endl;
        return 0;
}

void recursive(int cnt, int pos) {
        if (cnt == n-1) {
	return;
        }
        if (pos == -1) {
	for (int i = 0; i < 3; i++) sum[0][i] = v[0][i];
        }

        sum[cnt + 1][0] = min(sum[cnt][1] + v[cnt + 1][0], sum[cnt][2] + v[cnt + 1][0]);
        sum[cnt + 1][1] = min(sum[cnt][0] + v[cnt + 1][1], sum[cnt][2] + v[cnt + 1][1]);
        sum[cnt + 1][2] = min(sum[cnt][0] + v[cnt + 1][2], sum[cnt][1] + v[cnt + 1][2]);

        int index = min_element(sum[cnt + 1].begin(), sum[cnt + 1].end()) - sum[cnt + 1].begin();

        if (pos == -1) recursive(cnt + 1, index);
        else {
	vector<int>tmp;
	for (int i = 0; i < 3; i++) {
	        if (i == index) continue;
	        tmp.push_back(i);
	}
	if (sum[cnt + 1][tmp[0]] > sum[cnt + 1][tmp[1]]) recursive(cnt + 1, tmp[1]);
	else recursive(cnt + 1, tmp[0]);
        }

        return;
}
