///fibonacci recursion
#include<bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    cout<<"starting fibo("<<n<<")"<<endl;
    if(n<2)
        return n;
    int f=fibo(n-1)+fibo(n-2);
    cout<<"Done! fibo("<<n<<")= "<<f<<endl;
    return f;
}
int main()
{
    cout<<fibo(4)<<endl;
    return 0;
}
