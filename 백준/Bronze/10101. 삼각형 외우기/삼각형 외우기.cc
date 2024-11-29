#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int arr[3], sum =0;
        for (int i = 0; i < 3; i++) cin >> arr[i];
        sum = accumulate(arr, arr + 3, 0);
        if (sum != 180) {
	cout << "Error";
	return 0;
        }

        if (arr[0] == arr[1] && arr[1] == arr[2]) {
	cout << "Equilateral";
	return 0;
        }
        if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2]) {
	cout << "Isosceles";
	return 0;
        }
        if (arr[0] != arr[1] && arr[1] != arr[2] && arr[0] != arr[2]) {
	cout << "Scalene";
	return 0;
        }
        return 0;

}