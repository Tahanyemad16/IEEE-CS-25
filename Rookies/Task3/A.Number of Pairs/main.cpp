#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long l, r;
        cin >> n >> l >> r;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        long long count = 0;

        for (int i = 0; i < n; i++) {
            long long low = l - arr[i];
            long long high = r - arr[i];
            int left = lower_bound(arr.begin() + i + 1, arr.end(), low) - arr.begin();
            int right = upper_bound(arr.begin() + i + 1, arr.end(), high) - arr.begin();
            count += (right - left);
        }

        cout << count << endl;
    }
    return 0;
}
