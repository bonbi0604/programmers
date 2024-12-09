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

int gcd(int a, int b) {
        while (b != 0) {
	int tmp = a % b;
	a = b;
	b = tmp;
        }
        return a;
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int x_sum = x1 * y2 + x2 * y1;
        int y_sum = y1 * y2;
        int common = gcd(max(x_sum, y_sum), min(x_sum, y_sum));
        cout << x_sum / common << " " << y_sum / common << endl;
        return 0;
}

