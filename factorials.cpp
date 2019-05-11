///factorials using recursion
#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
    cout<<"calculating fact("<<n<<")"<<endl;
    if(n==0)
        return 1;
    int f=n*fact(n-1);
    cout<<"done! fact("<<n<<") is: "<<f<<endl;
    return f;
}
int main()
{
    cout<<fact(4)<<endl;
    return 0;
}
