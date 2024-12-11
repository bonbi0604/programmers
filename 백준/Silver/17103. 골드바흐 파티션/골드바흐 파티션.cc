#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
#include <stack>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int>partition(1000001, 1);
        partition[0] = 0;
        partition[1] = 0;
        for (int i = 2; i < partition.size(); i++) {
	for (int j = i + i; j < partition.size(); j = j + i) {
	        if (partition[j] == 0) continue;
	        else partition[j] = 0;
	}
        }

        int n;
        cin >> n;
        while (n--) {
	int number, cnt = 0;
	cin >> number;

	for (int i = 2; i <= number; i++) {
	        if (partition[i] == 1 && partition[number-i] == 1) {
		cnt++;
	        }
	        if(i == number-i) break;
	}
	cout << cnt << "\n";
        }
        return 0;
}

