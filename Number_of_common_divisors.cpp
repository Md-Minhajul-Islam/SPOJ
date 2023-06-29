// Q: https://www.spoj.com/problems/COMDIV/
#include<bits/stdc++.h>
using namespace std;
int GCD(int a, int b)
{
    return (b == 0) ? a : GCD(b, a%b);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int count = 0;
        int gcd = GCD(a, b);
        for(int i = 1; i*i <= gcd; i++)
        {
            if(i*i == gcd) count += 1;
            else if(gcd%i == 0) count += 2;
        }
        printf("%d\n", count);
    }
    return 0;
}