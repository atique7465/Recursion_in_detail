///fibonacci recursion with memoization [ O(n) ]
#include<bits/stdc++.h>
using namespace std;
int arr[100000000];

int fibo(int n)
{
    cout<<"starting fibo("<<n<<")"<<endl;
    if(n<2)
        return n;
    if(arr[n]!=0)
            return arr[n];
    arr[n]=fibo(n-1)+fibo(n-2);
    cout<<"Done! fibo("<<n<<")= "<<arr[n]<<endl;
    return arr[n];
}
int main()
{
    cout<<fibo(100000)<<endl;
    return 0;
}

