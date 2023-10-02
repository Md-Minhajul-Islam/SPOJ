// Q: https://www.spoj.com/problems/INTEST/en/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k; cin >> n >> k;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if(x%k == 0) ans += 1;
    }
    cout << ans;
    return 0;
}