/// modular exponential using recursion
/// x^n % m= {x^(n/2) %m * x^(n/2) %m} %m if n is even
/// x^n % m= {x%m * x^(n-1) %m} %m if n is odd
/// x^n % m= 1 if n is zero

#include<bits/stdc++.h>
using namespace std;
int mod_expo(int x, int n, int m)
{
    cout<<"calculating mod_expo("<<x<<"^"<<n<<","<<m<<")"<<endl;
    if (n==0)
        return 1;
    else if(n%2==0)
    {
        int y=mod_expo(x,n/2,m);
        cout<<"Done!!! mod_expo("<<x<<"^"<<n<<","<<m<<")= "<<y<<endl;
        y=(y*y)%m;
        return y;
    }
    else
    {
        int r=((x%m) * mod_expo(x,n-1,m))%m;
        cout<<"Done!!! mod_expo("<<x<<"^"<<n<<","<<m<<")= "<<r<<endl;
        return r;
    }
}
int main()
{
    cout<<mod_expo(2,4,3)<<endl;
    return 0;
}

