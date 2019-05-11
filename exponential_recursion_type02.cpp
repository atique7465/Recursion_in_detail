///exponential using recursion [ O(n) ]
///x^(n/2)*x^(n/2) for n is even
///x*x^(n-1) for n is odd
///1  for n=0;

#include<bits/stdc++.h>
using namespace std;

int expo(int x, int n)
{
    cout<<"starting expo("<<x<<"^"<<n<<")"<<endl;
    if(n==0)
        return 1;

    if(n%2==0)
    {
        int res=expo(x,n/2);
        cout<<"Done! expo("<<x<<"^"<<n<<")= "<<res*res<<endl;
        return res*res;
    }

    else
    {
        int ans=x*expo(x,n-1);
        cout<<"Done! expo("<<x<<"^"<<n<<")= "<<ans<<endl;
        return ans;
    }
}
int main()
{
    cout<<expo(2,8)<<endl;
    return 0;
}



