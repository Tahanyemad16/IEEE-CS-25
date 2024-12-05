#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int mntime = INT_MAX;
    bool found= false;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'R' && s[i + 1] == 'L') {
            int time = (v[i + 1] - v[i]) / 2;
            mntime = min(mntime, time);
            found = true;
        }
    }

    if (found) {
        cout << mntime << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}