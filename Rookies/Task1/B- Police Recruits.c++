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
    
    int police=0;
    int count =0;
    for (int i = 0; i < n; i++) {
      if(v[i]==-1){
        if(police==0){
          count++;
        }else{
         police --;
        }
      }else{
        police+=v[i];
      }
    }
    cout<<count<<"\n";
      
    return 0;
}