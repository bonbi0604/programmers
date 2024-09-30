#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<vector<int>> v;
int diff = 1000000;

// 비트마스크를 활용한 팀 차이 계산 함수
void compare(int team, int cnt, int idx) {
        if (cnt == n / 2) {
                int sumA = 0, sumB = 0;
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                                if ((team & (1 << i)) && (team & (1 << j))) {
                                        sumA += v[i][j];
                                }
                                else if (!(team & (1 << i)) && !(team & (1 << j))) {
                                        sumB += v[i][j];
                                }
                        }
                }
                diff = min(diff, abs(sumA - sumB));
                return;
        }

        for (int i = idx; i < n; i++) {
                compare(team | (1 << i), cnt + 1, i + 1);
        }
}

int main() {
        cin >> n;
        v.resize(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        cin >> v[i][j];
                }
        }

        compare(0, 0, 0);

        cout << diff << endl;

        return 0;
}
