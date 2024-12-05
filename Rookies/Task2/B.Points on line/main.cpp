#include <iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, d;
    cin >> n >> d;
    vector<long long >v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long count = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (v[i] - v[j] > d) {
            j++;
        }
        long long m = i - j;
        if (m >= 2) {
            count += (m * (m - 1)) / 2;
        }
    }
    cout << count << "\n";

    return 0;
}
