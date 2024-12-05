#include <iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long t;
    cin >> n >> t;
    vector<long long >v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long sum = 0;
    int j = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        while (sum > t) {
            sum -= v[j];
            j++;
        }
        mx = max(mx, i - j + 1);
    }

    cout << mx << "\n";

    return 0;
}
