// Q: https://www.spoj.com/problems/NAKANJ/cstart=30
#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> direction = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};
int visited[8][8];
int level[8][8];

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = 1;
    level[si][sj] = 0;
    while(!q.empty())
    {
        int ui, uj;
        ui = q.front().first;
        uj = q.front().second;
        q.pop();
        for(pair<int, int> v: direction)
        {
            int vi = ui+v.first;
            int vj = uj+v.second;
            if (vi >= 0 && vi < 8 && vj >= 0 && vj < 8 && !visited[vi][vj])
            {
                visited[vi][vj] = 1;
                level[vi][vj] = level[ui][uj]+1;;
                q.push({vi, vj});
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(level, 0, sizeof(level));
        memset(visited, 0, sizeof(visited));
        string s, d;
        cin >> s >> d;
        int si, sj, di, dj;
        si = s[1]-'1', sj = s[0]-'a';
        di = d[1]-'1', dj = d[0]-'a';
        bfs(si, sj);
        cout << level[di][dj] << "\n";
    }
    return 0;
}