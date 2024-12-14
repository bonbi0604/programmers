#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <sstream>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
#include <stack>
using namespace std;

enum kind{
        Push,
        Pop,
        Size,
        Empty,
        Front,
        Back
};

kind fp(string s) {
        if (s == "push") return Push;
        if (s == "pop") return Pop;
        if (s == "size") return Size;
        if (s == "empty") return Empty;
        if (s == "front") return Front;
        if (s == "back") return Back;
}

int main(int argc, char *argv[]) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n;
        cin >> n;
        queue<int>q;

        for (int i = 0; i < n; i++) {
	string str;
	cin >> str;
	kind command = fp(str);

	if (command == Push) {
	        int n;
	        cin >> n;
	        q.push(n);
	}
	else if (command == Pop) {
	        if (q.empty()) cout << -1 << "\n";
	        else {
		cout << q.front() << "\n";
		q.pop();

	        }
	}
	else if (command == Size) {
	        cout << q.size() << "\n";
	}
	else if (command == Empty) {
	        if (q.empty()) cout << 1 << "\n";
	        else cout << 0 << "\n";
	}
	else if (command == Front) {
	        if (q.empty()) cout << -1 << "\n";
	        else cout << q.front() << "\n";
	}
	else {
	        if (q.empty()) cout << -1 << "\n";
	        else cout << q.back() << "\n";
	}


        }

        return 0;
}

