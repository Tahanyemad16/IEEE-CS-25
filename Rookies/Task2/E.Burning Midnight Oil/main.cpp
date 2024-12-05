#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    cin >> n >> m;

    long long start = 1;
    long long end = n;
    long long res = n;

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        long long all = 0;
        long long curr = mid;
        while (curr > 0)
        {
            all += curr;
            curr /= m;
            if (all >= n)
                break;
        }
        if (all >= n)
        {
            res = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    cout << res << endl;
    return 0;
}
