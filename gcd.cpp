#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    int a=6,b=16;
    int x=gcd(a,b);
    cout<<x;
    return 0;
}
