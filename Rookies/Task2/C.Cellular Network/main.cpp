#include <iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n, m;
    cin >> n >> m;
    vector<long long> cities(n), towers(m);

    for (int i = 0; i < n; i++)
        cin >> cities[i];
    for (int i = 0; i < m; i++)
        cin >> towers[i];

    long long start = 0, end = 2LL * 1e9, res = end;

    while (start <= end) {
        long long mid = start + (end - start) / 2;
        bool all = true;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && abs(towers[j] - cities[i]) > mid)
                j++;

            if (j == m) {
                all = false;
                break;
            }
        }

        if (all) {
            res = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    cout << res << endl;
    return 0;
}
