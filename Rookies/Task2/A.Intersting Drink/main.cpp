#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long q;
    cin >> q;

    while (q--) {
        int m;
        cin >> m;

        auto it = upper_bound(v.begin(), v.end(), m);
        cout << (it - v.begin()) << "\n";
    }

    return 0;
}
