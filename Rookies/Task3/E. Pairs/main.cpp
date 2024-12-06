#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (binary_search(arr.begin() + i + 1, arr.end(), arr[i] + k)) {
            count++;
        }
    }

    cout << count;
    return 0;
}
