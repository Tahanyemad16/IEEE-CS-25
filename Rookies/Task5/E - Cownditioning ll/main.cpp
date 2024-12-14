#include <iostream>
#include<climits>
#include <vector>
using namespace std;

struct Cow {
    int start, end, cooling;
};

struct air{
    int start, end, power, cost;
};

int n,m;
vector<Cow> cows;
vector<air> acs;
int minCost = INT_MAX;

void applyCool(vector<int>& cooling, const air& ac, bool add) {
    int effect = add ? ac.power : -ac.power;
    for (int i = ac.start; i <= ac.end; i++) {
        cooling[i] += effect;
    }
}

bool isValid(const vector<int>& cooling) {
    for (const auto& cow : cows) {
        for (int i = cow.start; i <= cow.end; i++) {
            if (cooling[i] < cow.cooling) {
                return false;
            }
        }
    }
    return true;
}

void back(int idx, int cost, vector<int>& cooling) {
    if (idx == m) {
        if (isValid(cooling)) {
            minCost = min(minCost, cost);
        }
        return;
    }
    back(idx + 1, cost, cooling);
    applyCool(cooling, acs[idx], true);
    back(idx + 1, cost + acs[idx].cost, cooling);
    applyCool(cooling, acs[idx], false);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n>> m;
    cows.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].start >> cows[i].end >> cows[i].cooling;
    }
    acs.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> acs[i].start >> acs[i].end >> acs[i].power >> acs[i].cost;
    }
    vector<int> cooling(101, 0);
    back(0, 0, cooling);
    cout << minCost << endl;
    return 0;
}
