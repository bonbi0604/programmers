#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {

        cin.tie(NULL);
        cout.tie(NULL);
        map<int, int>m;
        int a, b, num, answer = 0;
        cin >> a >> b;
        for (int i = 0; i < a; i++) {
	cin >> num;
	m[num]++;
        }
        for (int i = 0; i < b; i++) {
	cin >> num;
	m[num]++;
        }
        for (auto e : m) {
	if (e.second == 1) answer++;
        }
        cout << answer;

        return 0;
}