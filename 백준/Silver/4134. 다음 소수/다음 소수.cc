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

bool check(long long number) {
        for (int i = 2; i <= sqrt(number)+1; i++) {
	if (number % i == 0) return false;
        }
        return true;
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<long long>v;
        
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
	long long number;
	cin >> number;
	if (number == 0 || number == 1 || number ==2) {
	        cout << 2 << endl;
	        continue;
	}
	while (1) {
	        if (!check(number)) {
		number++;
	        }
	        else {
		cout << number << endl;
		break;
	        }
	}

        }

        return 0;
}
