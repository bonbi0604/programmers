#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <sstream>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <deque>
using namespace std;


int main(int argc, char* argv[]) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n, cnt=0;
        cin >> n;
        deque<pair<int, int>>q;
        for (int i = 1; i <= n; i++) {
	int tmp;
	cin >> tmp;
	q.push_back({ i, tmp });
        }
        vector<int>answer;
        while (!q.empty()) {
	if (cnt > 0) {
	        while (cnt > 0) {
		q.push_back({ q.front().first, q.front().second });
		q.pop_front();
		cnt--;
	        }
	}
	else if (cnt < 0) {
	        cnt = abs(cnt);
	        while (cnt > 0) {
		q.push_front({ q.back().first, q.back().second });
		q.pop_back();
		cnt--;
	        }
	}
	else {
	        if (cnt == 0) {
		answer.push_back(q.front().first);
		cnt = q.front().second > 0 ? q.front().second - 1 : q.front().second;
		q.pop_front();
	        }
	}
        }
        for (auto e : answer) cout << e << " ";
}