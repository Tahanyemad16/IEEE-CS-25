#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int left = 0, right = n - 1;
    int a = 0, b = 0, c = 0, d = 0;

    while (left <= right) {
        if (a <= b) {
            a += v[left];
            left++;
            c++;
        } else {
            b += v[right];
            right--;
            d++;
        }
    }

    cout << c << " " << d;
    return 0;
}
