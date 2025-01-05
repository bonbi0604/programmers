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
        deque<int>dq;
        int n;
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; i++) {
	vector<int>tmp;
	string s, temp;
	getline(cin, s);
	stringstream ss(s);
	while (getline(ss, temp, ' ')) tmp.push_back(stoi(temp));
	
	if (tmp.size() == 2) {
	        if (tmp[0] == 1) dq.push_front(tmp[1]);
	        else dq.push_back(tmp[1]);
	}
	else {
	        if (tmp[0] == 3) {
		if (dq.empty()) cout << -1 << "\n";
		else {
		        cout << dq.front() << "\n";
		        dq.pop_front();
		}
	        }
	        else if (tmp[0] == 4) {
		if (dq.empty()) cout << -1 << "\n";
		else {
		        cout << dq.back() << "\n";
		        dq.pop_back();
		}
	        }
	        else if (tmp[0] == 5) {
		cout << dq.size() << "\n";
	        }
	        else if (tmp[0] == 6) {
		if (dq.empty()) cout << 1 << "\n";
		else cout << 0 << "\n";
	        }
	        else if (tmp[0] == 7) {
		if (dq.empty()) cout << -1 << "\n";
		else cout << dq.front() << "\n";
	        }
	        else {
		if (dq.empty()) cout << -1 << "\n";
		else cout << dq.back() << "\n";
	        }
	}
	        
	tmp.clear();
        }


        return 0;
}

