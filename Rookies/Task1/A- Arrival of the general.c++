#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int>v(n);

    for (int i = 0; i < n; i++) {
        cin >>v[i];
    }
    
    int mxindex=0;
    int mnindex=0;
    
    for (int i = 0; i < n; i++) {
        if (v[mxindex]<v[i]) {
            mxindex= i;
        }
        if (v[mnindex]>=v[i]) {
            mnindex = i;
        }
    }
    
    int res=mxindex+((n-1)-mnindex);
    if(mxindex>mnindex)
      cout<<res-1<<"\n";
    else
      cout<<res<<"\n";
      
    return 0;
}