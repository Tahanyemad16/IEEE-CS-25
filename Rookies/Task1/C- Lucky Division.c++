#include <bits/stdc++.h>
using namespace std;
bool lucky(int x){
    while (x!=0) {
        if(x%10==4||x%10==7){
          x/=10;
        }else{
          return false;
        }
    }
    return true ;
 }
int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    if(lucky(n))
      cout<<"YES\n";
    else{
      vector <int>v;
      for(int i=1;i<=1000;i++){
        if(lucky(i))
          v.push_back(i);
      }
      bool flag =false ;
      for(int i=0;i<v.size();i++){
        if(n%v[i]==0){
          flag=true ;
          break;
        }else{
          continue ;
        }
      }
      if(flag)
        cout<<"YES\n";
      else
        cout<<"NO\n"  ;
    }
      
    return 0;
}