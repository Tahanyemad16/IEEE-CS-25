#include <iostream>
#include <set>
#include <string>
#include <cstring>
using namespace std;

void generatePermutations(string curPer, string &original, int size, bool vis[], set<string> &permutations) {
    if (curPer.size() == size) {
        permutations.insert(curPer);
        return;
    }
    for (int i = 0; i < size; ++i) {
        if (!vis[i]) {
            vis[i] = true;
            generatePermutations(curPer + original[i], original, size, vis, permutations);
            vis[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string original;
    cin >> original;
    int size= original.size();
    bool vis[10] = {false};
    set<string> permutations;

    generatePermutations("", original, size, vis, permutations);

    cout << permutations.size() << '\n';
    for (const auto &perm : permutations) {
        cout << perm << "\n";
    }

    return 0;
}
