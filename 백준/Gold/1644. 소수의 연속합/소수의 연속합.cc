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
using namespace std;


int main(int argc, char *argv[]) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);


        int answer = 0, n;
        cin >> n;
        vector<int>v(n+1, 1), prime, sum_prime;
        v[0] = 0;
        v[1] =  0;
        
        for (int i = 2; i <= n; i++) {
	for (int j = i*2; j <= n; j = j + i) {
	        if (v[j] == 0) continue;
	        v[j] = 0;
	}
        }
     
        for (int i = 2; i <= n; i++) if (v[i] == 1) prime.push_back(i);
        sum_prime.resize(prime.size()+1);
        for (int i = 0; i < prime.size(); i++) {
	sum_prime[i+1] = sum_prime[i] + prime[i];
        }

        int start = 0, end = 0;
        while (end < sum_prime.size()) {
	int std = sum_prime[end] - sum_prime[start];
	if (std == n) {
	        answer++;
	        end++;
	}
	else if (std > n) {
	        start++;
	}
	else if (std < n) {
	        end++;
	}
        }

        cout << answer << endl;
        return 0;
}

