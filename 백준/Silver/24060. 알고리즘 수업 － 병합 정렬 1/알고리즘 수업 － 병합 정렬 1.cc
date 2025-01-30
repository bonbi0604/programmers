#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
vector<int>arr,tmp;
int cnt = 0, num, answer = -1;

void merge(int start, int mid, int end) {
        int i = start;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= end) {
                if (arr[i] <= arr[j]) {
                        tmp[k++] = arr[i++];
                }
                else {
                        tmp[k++] = arr[j++];
                }
        }
        while (i <= mid) {
                tmp[k++] = arr[i++];
        }
        while (j <= end) {
                tmp[k++] = arr[j++];
        }      
        i = start;
        k = 0;
        while (i <= end) {
                arr[i++] = tmp[k++];
                cnt++;
                if (cnt == num) {
                        answer = arr[i - 1];
                        break;
                }
        }
}

void merge_sort(int start, int end) {
        if (start >= end) return;
        int mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid+1, end);
        merge(start, mid, end);
        return;
}

int main() {
        int n;
        cin >> n >> num;
        arr.resize(n);
        tmp.resize(n);
        for (int i = 0;i < n;i++) cin >> arr[i];
        merge_sort(0, n-1);
        cout << answer << endl;
        return 0;
}