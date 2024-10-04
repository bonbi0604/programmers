#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n;
        cin >> n;
        stack<int>st;

        for (int i = 0; i < n; i++) {
	int num;
	cin >> num;
	if (num == 1) {
	        int tmp;
	        cin >> tmp;
	        st.push(tmp);
	}
	else if (num == 2) {
	        if (!st.empty()) {
		cout << st.top() << "\n";
		st.pop();
	        }
	        else {
		cout << -1<< "\n";
	        }
	}
	else if (num == 3) {
	        cout << st.size() << "\n";
	}
	else if (num == 4) {
	        if (st.empty()) {
		cout << 1 << "\n";
	        }
	        else cout << 0 << "\n";
	}
	else if (num == 5) {
	        if (st.empty()) {
		cout << -1 << "\n";
	        }
	        else {
		cout << st.top() << "\n";
	        }
	}
        }

        return 0;
}
