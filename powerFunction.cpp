#include<iostream>
using namespace std;



int power(int x, unsigned y)
{
    if (y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);
}  

int main() {
    int x; int n; int d;
    x = -1;
    n=1;
    d=20;
    int res = power(x,n);
    cout<<res<<endl;
    int X = res;
    int Y = d;
    int result = X % Y + (X % Y < 0 ? Y : 0);
    cout<<result<<endl;
     return 0;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}