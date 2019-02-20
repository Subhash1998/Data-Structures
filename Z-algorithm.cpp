#include <iostream>
using namespace std;

int main()
{
    string txt,pat;
    cin>>txt>>pat;
    int i,j,n,left=0,right=0,k=0,k1;
    string s = pat+"$"+txt;
    n = s.length();
    int Z[1000];
    Z[0]=0;
    for(k=1;k<n;k++)
    {
        if(k>right)
        {
            right = left = k;
            while(right<n && s[right]==s[right-left])
            {
                right++;
            }
            Z[k] = right-left;
            right--;
        }
        else
        {
            k1 = k - left;
            
            if(Z[k1] < right - k + 1 )
            {
                Z[k] = Z[k1];
            }
            else
            {
                left = k;
                while(right<n && s[right]==s[right-left])
                {
                    right++;
                }
                Z[k] = right-left;
                right--;
            }
        }
    }
    return 0;
}
