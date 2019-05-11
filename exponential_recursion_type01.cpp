///exponential using recursion [ O(n) ]
///x*x^(n-1) for n>o
///1  for n=0;

#include<bits/stdc++.h>
using namespace std;

int expo(int x, int n)
{
    cout<<"starting expo("<<x<<"^"<<n<<")"<<endl;
    if(n==0)
      return 1;

    int res=x*expo(x,n-1);
    cout<<"Done! expo("<<x<<"^"<<n<<")= "<<res<<endl;
    return res;
}
int main()
{
    cout<<expo(2,8)<<endl;
    return 0;
}


