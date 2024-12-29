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

long long a, b, c, ans;
long long func(long long b) {
        if (b == 0) return 1;
        if (b == 1) return a % c;
        ans = func(b / 2) % c;
        if (b % 2 == 0) return ans * ans % c;
        return ans * ans % c * a % c;
}

int main(int argc, char *argv[]) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin >> a >> b >> c;
        cout << func(b);

        return 0;
}

