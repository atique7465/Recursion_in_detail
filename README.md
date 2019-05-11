# Recursion_in_detail
Some basic codes and their complexity analysis using recursion to get some awesome intuition about recursive programming. Lets dig in.

Part 01:
///factorials using recursion
#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
    cout<<"calculating fact("<<n<<")"<<endl;
    if(n==0)        /// 1 unit time for checking
        return 1;
    int f=n*fact(n-1);   /// 2 unit time for multiply and subtraction of (n-1)
    cout<<"done! fact("<<n<<") is: "<<f<<endl;
    return f;
}
int main()
{
    cout<<fact(4)<<endl;
    return 0;
}
output:
calculating fact(4) 
calculating fact(3) 
calculating fact(2) 
calculating fact(1) 
calculating fact(0) 
done! fact(1) is: 1 
done! fact(2) is: 2 
done! fact(3) is: 6 
done! fact(4) is: 24 
24 
link to resourse: https://www.youtube.com/watch?v=_OmRGjbyzno&list=PL2_aWCzGMAwLz3g66WrxFGSXvSsvyfzCO

part 02
Time complexity: factorials.cpp
t(n)=t(n-1)+3. for all n>0;
t(0)=1;
so,
t(n)=t(n-1)+3
t(n)=t(n-2)+3+3 or 6
t(n)=t(n-3)+9
t(n)=t(n-4)+12
t(n)=t(n-k)+3*k
at last, n-k=0; n=k
so, t(n)=t(0)+3*n  
so, t(n)∞ n or O(n)

space Complexity: O(n)
as, the code uses an N sized implecit Stack” to execute the recurent functions.
link to resourse: https://www.youtube.com/watch?v=ncpTxqK35PI&list=PL2_aWCzGMAwLz3g66WrxFGSXvSsvyfzCO&index=3

part 03:
///fibonacci iterative
#include<bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    if(n<2)
        return n;
    int a=0,b=1;
    int c;
    for(int i=2; i<=n; i++) /// n unit time
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main()
{
    cout<<fibo(10)<<endl;
    return 0;
}
output: 55

///fibonacci recursion
#include<bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    cout<<"starting fibo("<<n<<")"<<endl;
    if(n<2)   /// 1 unit time to compare
        return n;
    int f=fibo(n-1)+fibo(n-2);  /// 3 unit time
    cout<<"Done! fibo("<<n<<")= "<<f<<endl;
    return f;
}
int main()
{
    cout<<”res= ”<<fibo(4)<<endl;
    return 0;
}
output:
starting fibo(4) 
starting fibo(3) 
starting fibo(2) 
starting fibo(1) 
starting fibo(0) 
Done! fibo(2)= 1 
starting fibo(1) 
Done! fibo(3)= 2 
starting fibo(2) 
starting fibo(1) 
starting fibo(0) 
Done! fibo(2)= 1 
Done! fibo(4)= 3 
res= 3
link to resourse: https://www.youtube.com/watch?v=GM9sA5PtznY&list=PL2_aWCzGMAwLz3g66WrxFGSXvSsvyfzCO&index=2

Part 04:
##Time complexity: fibonacci_recursion.cpp
t(n)=t(n-1)+t(n-2)+4   for all n>=2;
t(n)=t(1)=1;
let assume, t(n-1) = t(n-2) [approximately]
so,
t(n)=2*t(n-2)+c  [c=4 or constant]
t(n)=2*{2*t(n-4)+c}+c
t(n)=4*t(n-4)+3c
t(n)=8*t(n-6)+7c
t(n)=16*t(n-8)+15c

so, T(n)=2^k*T(n-2k)+(2^k-1)c
so, n-2k=0 or k=n/2
so, T(n)= 2^(n/2) * T(0) + {2^(n/2) -1}c
            =(1+c)*2^(n/2) -c
so, T(n) ∞ 2^(n/2) [lower bound,exponentiol]

let assume, t(n-2) = t(n-1) [approximately]
so,
t(n)=2*t(n-1)+c  [c=4 or constant]
t(n)=4*t(n-2)+3c
t(n)=8*t(n-3)+7c
t(n)=16*t(n-4)+15c

so, T(n)=2^k*T(n-k)+(2^k-1)c
so, n-k=0 or k=n
so, T(n)= 2^(n) * T(0) + {2^(n) -1}c
            =(1+c)*2^(n) -c
so, T(n) ∞ 2^n [upper bound,exponential]

so, O(2^n) → fibo_recursive time complexity.
but , O(n) → fibo iterative time complexity.which is linear.
linear complexity is better than exponential complexity.

##Space Complexity(recursive): O(n) as, implicit stack to store recursive functions states. So space complexity is the longest depth of the recursion tree.
##Space Complexity(Iterative): O(1) as, no need of implecit stack, just some explicit variable like a,b,c etc..
 
link to resourse: https://www.youtube.com/watch?v=pqivnzmSbq4&list=PL2_aWCzGMAwLz3g66WrxFGSXvSsvyfzCO&index=4
link to resourse: https://www.youtube.com/watch?v=dxyYP3BSdcQ&list=PL2_aWCzGMAwLz3g66WrxFGSXvSsvyfzCO&index=6


part 05:
code without memoization works better for input ‘10’. what if the input is ‘40’. it will take so much time. Thats where memoization comes handy. It turn the time complexity very lessser and produce uotput quickly.

///fibonacci recursion with memoization [ O(n) ]
#include<bits/stdc++.h>
using namespace std;
int arr[10000000];
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
    cout<<fibo(5)<<endl;
    return 0;
}	
Output:
starting fibo(5) 
starting fibo(4) 
starting fibo(3) 
starting fibo(2) 
starting fibo(1) 
starting fibo(0) 
Done! fibo(2)= 1 
starting fibo(1) 
Done! fibo(3)= 2 
starting fibo(2) 
Done! fibo(4)= 3 
starting fibo(3) 
Done! fibo(5)= 5 
5

space complexity: O(n).as before.
Time complexity: O(n).as the fuctions called twice at lest and executed in O(1) because of memoization.

The memoization version will take O(n) time on first run, since each number is only computed once. However, in exchange, it also take O(n) memory for your current implementation (the n comes from storing the computed value, and also for the stack on the first run). If you run it many times, the time complexity will become O(M + q) where M is the max of all input n and q is the number of queries. The memory complexity will become O(M), which comes from the array which holds all the computed values.

As plesiv mentioned, the Fibonacci number can also be computed in O(log n) by matrix multiplication (using the same trick as fast exponentiation by halving the exponent at every step).
A java implementation to find Fibonacci number using matrix multiplication is as follows:
https://stackoverflow.com/questions/13440020/big-o-for-various-fibonacci-implementations
link to resourse: https://www.youtube.com/watch?v=UxICsjrdlJA&list=PL2_aWCzGMAwLz3g66WrxFGSXvSsvyfzCO&index=5

part 06:
power exponential using recursion.
Type 01:
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
    cout<<expo(2,3)<<endl;
    return 0;
}
output:
starting expo(2^8)
starting expo(2^7)
starting expo(2^6)
starting expo(2^5)
starting expo(2^4)
starting expo(2^3)
starting expo(2^2)
starting expo(2^1)
starting expo(2^0)
Done! expo(2^1)= 2
Done! expo(2^2)= 4
Done! expo(2^3)= 8
Done! expo(2^4)= 16
Done! expo(2^5)= 32
Done! expo(2^6)= 64
Done! expo(2^7)= 128
Done! expo(2^8)= 256
256

Type 02:
///exponential using recursion [ O(log n) ]
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
output:
starting expo(2^8)
starting expo(2^4)
starting expo(2^2)
starting expo(2^1)
starting expo(2^0)
Done! expo(2^1)= 2
Done! expo(2^2)= 4
Done! expo(2^4)= 16
Done! expo(2^8)= 256
256

link to resourse: https://www.youtube.com/watch?v=wAyrtLAeWvI&list=PL2_aWCzGMAwLz3g66WrxFGSXvSsvyfzCO&index=7


part 07:
/// modular exponential using recursion [O(logn)]
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
	Output:
calculating mod_expo(2^4,3)
calculating mod_expo(2^2,3)
calculating mod_expo(2^1,3)
calculating mod_expo(2^0,3)
Done!!! mod_expo(2^1,3)= 2
Done!!! mod_expo(2^2,3)= 2
Done!!! mod_expo(2^4,3)= 1
1

Time Complexity:
t(n)=t(n/2)+c1, if n is even
t(n)=t(n-1)+c2, if n is even
t(o)=1, t(1)=1+c2
so, if n is odd then
t(n)=t(n-1)+c2
t(n-1)=t{(n-1)/2}+c1+c2
so taking ni is even is upper bound cause t(n/2)=t{(n-1)/2} appoximately,
so, t(n)=t(n/2)+c, c>c1
           =t(n/4)+2c
           =t(n/8)+4c
           .
           .
          =t{n/(2^k)}+kc …….(1)
n/(2^k)=1 => 2^k=n => k=log2 (n)
so, (1)=> t(n)=1+c2+c log n

so, O(log n)

link to resourse: https://www.youtube.com/watch?v=nO7_qu2kd1Q&list=PL2_aWCzGMAwLz3g66WrxFGSXvSsvyfzCO&index=8
link to resourse: https://www.youtube.com/watch?v=VHcZtdp5054&list=PL2_aWCzGMAwLz3g66WrxFGSXvSsvyfzCO&index=9
