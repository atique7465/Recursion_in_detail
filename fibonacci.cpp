///fibonacci iterative
#include<bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    if(n<2)
        return n;
    int a=0,b=1;
    int c;
    for(int i=2; i<=n; i++)
    {
        c=a+b;
        a=b;
        b=c;
        cout<<c<<" ";
    }
    cout<<endl;
    return c;
}
int main()
{
    cout<<fibo(10)<<endl;
    return 0;
}
