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
        int n;
        cin >> n;
        vector<int>a(n);
        vector<int>b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int num;
        cin >> num;

        for (int i = n - 1; i >= 0; i--) {
	if (a[i] == 0) {
	        cout << b[i] << " ";
	        num--;
	}
	if (num == 0) break;
        }

        while (num--) {
	int tmp;
	cin >> tmp;
	cout << tmp << " ";
        }

        return 0;
}