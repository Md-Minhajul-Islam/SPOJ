// Q: 
#include<bits/stdc++.h>
using namespace std;
bool prime[100];
void markPrime()
{
    prime[0] = prime[1] = 1;
    for(int i = 2; i*i <= 100; i++)
    {
        if(prime[i] == 0)
            for(int j = i*i; j <= 100; j+= i)
                prime[j] = 1;
    }
}
int divisor(int num)
{
    int divisors = 1;
    for(int i = 2; i*i <= num; i++)
    {
        int cnt = 0;
        while(num%i == 0)
        {
            num /= i;
            cnt++;
        }
        if(cnt) divisors *= (cnt+1);
    }
    if(num > 1) divisors *= 2;
    return divisors;
}
bool check(int num)
{
    for(int i = 2; i*i <= num; i++)
    {
        if(num%i == 0 && (num/i) != i)
        {
            if (prime[i] == 0 && prime[num / i] == 0)
                return true;
        }
    }
    return false;
}
int main()
{
    markPrime();
    vector<int> v;
    for(int i = 1; i <= 1000000; i++)
    {
        int numOfDivisor = divisor(i);
        bool ans = check(numOfDivisor);
        if(ans) v.push_back(i);
    }
    for(int i = 8; i < 50; i+=9)
     cout << v[i] << endl;
    return 0;
}