#include <iostream>
using namespace std;

 void algorithm(long long n){
  cout<<n<<" ";

  if(n==1)
    return ;

  if(n%2==0)  {
    algorithm(n/2);
  }else{
    algorithm(n*3+1);
  }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin>>n;

    algorithm(n);

    return 0;
}
