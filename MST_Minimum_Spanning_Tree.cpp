// Q: https://www.spoj.com/problems/MST/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> pii;
const int N = 1e5;
vector<pii> edge;
int parent[N], Size[N];
long long cost = 0;
void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
}
int find(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}
void Union(int a, int b)
{
    a = find(a), b = find(b);
    if (a != b)
    {
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}
void kruskalsAlgo()
{
    sort(edge.begin(), edge.end());
    for (pii e : edge)
    {
        int u = e.second.first, v = e.second.second, w = e.first;
        if (find(u) == find(v))
            continue;
        cost += w;
        Union(u, v);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        make(i);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({w, {u, v}});
    }
    kruskalsAlgo();
    cout << cost;
    return 0;
}