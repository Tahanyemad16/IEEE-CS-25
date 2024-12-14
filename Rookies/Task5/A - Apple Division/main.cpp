#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long distance(vector<long long>& v,int index, long long group1, long long group2){
   if(index==v.size()){
     return abs(group1-group2);
   }
  long long sum1=distance(v,index+1, group1+v[index],group2);
  long long sum2=distance(v,index+1,group1, group2+v[index]);

  return min(sum1,sum2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector <long long > apples(n);

    for(int i=0;i<n;i++)
      cin>>apples[i];

    cout<<distance(apples,0,0,0)<<"\n";
    return 0;
}
