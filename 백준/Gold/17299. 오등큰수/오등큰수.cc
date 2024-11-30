#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <stack>
#include <map>
using namespace std;

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n;
        cin >> n;
        vector<int>count(1000010, 0);
        vector<int>answer(n,-1), tmp;
        stack<int>s;
        for (int i = 0; i < n; i++) {
	int num;
	cin >> num;
	tmp.push_back(num);
	count[num]++;
        }

        for (int i = n - 1; i >= 0; i--) {
	while (!s.empty() && count[tmp[i]] >= count[s.top()]) {
	        s.pop();
	}
	if (!s.empty()) answer[i] = s.top();
	s.push(tmp[i]);
        }

        for (int i = 0; i < n; i++) cout << answer[i] << " ";
        
        return 0;

}