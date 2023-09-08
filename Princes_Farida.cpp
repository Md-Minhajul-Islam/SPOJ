// Q: https://www.spoj.com/problems/FARIDA/en/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
long long val[N], dp[N];
long long maxCoin(int n)
{
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    long long op1 = maxCoin(n-2)+val[n];
    long long op2 = maxCoin(n-1);
    return dp[n] = max(op1, op2);
}
int main()
{
    int t;
    cin >> t;
    for(int caseNo = 1; caseNo <= t; caseNo++)
    {
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> val[i];
        cout << "Case " << caseNo <<": " << maxCoin(n-1) <<"\n";
    }
    return 0;
}