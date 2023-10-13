// Q: https://www.spoj.com/problems/OLOLO/en/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    unordered_map<int, int> m;
    while(n--)
    {
        int x; cin >> x;
        m[x]++;
    }
    for(auto i: m)
    {
        if(i.second != 1) continue;
        cout << i.first <<"\n";
        break;
    }
    return 0;
}