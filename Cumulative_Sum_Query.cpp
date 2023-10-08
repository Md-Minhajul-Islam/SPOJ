// Q: https://www.spoj.com/problems/CSUMQ/en/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    long long a[n][2];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i][0];
        if(i == 0) a[i][1] = a[i][0];
        else a[i][1] = a[i-1][1]+a[i][0];
    }
    int q; cin >> q;
    while(q--)
    {
        int i, j; cin >> i >> j;
        if(i == 0) cout << a[j][1] <<"\n";
        else cout << a[j][1]-a[i-1][1] << "\n";
    }
    return 0;
}