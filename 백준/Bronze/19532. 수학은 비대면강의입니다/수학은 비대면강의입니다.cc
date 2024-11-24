#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <queue>
#include <numeric>
using namespace std;

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        double a, b, c, d, e, f;
        int x, y;

        cin >> a >> b >> c >> d >> e >> f;

        double det = a * e - b * d;

        if (det != 0) {
	x = (c * e - b * f) / det;
	y = (a * f - c * d) / det;
        }
        cout << x << " " << y << endl;

        return 0;
}