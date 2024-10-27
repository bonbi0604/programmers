#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        long n, cnt = 0, answer = 0;;
        cin >> n;
        vector<pair<long, long>>v(n);
        vector<long>tmp1(n-1), tmp2(n);
        for (int i = 0; i < n - 1; i++) {
	cin >> tmp1[i];
	cnt += tmp1[i];
        }
        
        for (int i = 0; i < n; i++) {
	cin >> tmp2[i];
        }

        for (int i = 0; i < n - 1; i++) {
	v[i] = { tmp2[i], tmp1[i] };
        }

        int pos = 1, cur =0;
        while (pos < n) {
	if (v[cur].first > v[pos].first) {
	        answer += v[cur].first * v[cur].second;
	        cur = pos;
	}else {
	        answer += v[cur].first * v[pos].second;
	}
	pos++;
        }
        cout << answer << endl;
        return 0;
}
