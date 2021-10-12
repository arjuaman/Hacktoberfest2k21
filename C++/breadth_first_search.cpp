#include <bits/stdc++.h>
using namespace std;

vector<int> arr[10001];
int vis[10001];
int dis[10001];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    dis[src] = 0;
    while (q.size())
    {
        int curr = q.front();
        q.pop();
        for (int child : arr[curr])
        {
            if (vis[child] == 0)
            {
                q.push(child);
                vis[child] = 1;
                dis[child] = dis[curr] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            vis[i] = 0;
            dis[i] = 0;
            arr[i].clear();
        }
        int a, b;
        while (m--)
        {
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        bfs(1);
        cout << dis[n] << endl;
    }
}