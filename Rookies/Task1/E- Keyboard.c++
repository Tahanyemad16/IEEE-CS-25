#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

   string ss="qwertyuiopasdfghjkl;zxcvbnm,./";
   
    char c;
    cin>>c;
     
    string s;
    cin >> s;

    string st="";
    
    for (int i = 0; i <s.length(); i++){
      for (int j= 0; j <ss.length(); j++){
        if(s[i]==ss[j]){
          if(c=='R'&&j-1>=0)
            st+=ss[j-1];
          else if(c=='L'&&j+1<ss.length())
            st+=ss[j+1];
              
        }
      }
    }
    
     cout<<st<<"\n";
    return 0;
}