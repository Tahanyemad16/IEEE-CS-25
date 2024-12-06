#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int left = 0, right = 0, maxCount = 0;

    while (right < n) {
        if (a[right] - a[left] > 5) {
            left++;
        } else {
            maxCount = max(maxCount, right - left + 1);
            right++;
        }
    }

    cout << maxCount;
    return 0;
}
