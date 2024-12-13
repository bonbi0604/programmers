#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
#include <stack>
using namespace std;


int main(int argc, char *argv[]) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n, people=1;
        cin >> n;
        vector<int>v(n);
        stack<int>st;
        for (int i = 0; i < n; i++) cin >> v[i];
        
        for (int i = 0; i < n; i++) {
	int tmp= -1;
	if (!st.empty()) tmp = st.top();

	if (v[i] == people) {
	        people++;
	}else if (tmp == people) {
	        i--;
	        people++;
	        st.pop();
	}
	else if (v[i] != people && tmp != people) {
	        st.push(v[i]);
	}
        }
        while (!st.empty()) {
	if (people++ == st.top()) {
	        st.pop();
	}
	else break;
        }
        if (st.empty()) cout << "Nice";
        else cout << "Sad";

        return 0;
}

