#include <iostream>
using namespace std;

int fib(int n){
 if(n==0||n==1)
   return n;
 else{
   return fib(n-1)+fib(n-2);
 }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    cout<<fib(n)<<"\n";

    return 0;
}
/*
STDIN   Function
-----   --------
3       n = 3
*/
