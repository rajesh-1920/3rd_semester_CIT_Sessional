#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

vector<pair<int, int>> graph[N];

// ========== BFS ==========
void BFS(int start, int goal)
{
    vector<bool> vis(N, false);
    queue<int> q;
    q.push(start);
    vis[start] = true;
    cout << "BFS : ";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << ' ';
        for (auto it : graph[u])
        {
            if (!vis[it.first])
            {
                vis[it.first] = true;
                q.push(it.first);
            }
        }
    }
    cout << '\n';
}

// ========== DFS ==========
void dfs(int n, int goal, vector<bool> &vis)
{
    vis[n] = true;
    cout << n << ' ';
    for (auto it : graph[n])
    {
        if (!vis[it.first])
            dfs(it.first, goal, vis);
    }
}
void DFS(int start, int goal)
{
    vector<bool> vis(N, false);
    cout << "DFS : ";
    dfs(start, goal, vis);
    cout << '\n';
}
// ========== DLS ==========
void dls(int n, int goal, int limit, vector<bool> &vis)
{
    if (limit == 0)
        return;
    vis[n] = true;
    cout << n << ' ';
    for (auto it : graph[n])
    {
        if (!vis[it.first])
            dls(it.first, goal, limit - 1, vis);
    }
}
void DLS(int start, int goal, int limit, int t = 0)
{
    vector<bool> vis(N, false);
    if (t == 0)
        cout << "DLS : ";
    else
        cout << "DLS" << t << " : ";
    dls(start, goal, limit, vis);
    cout << '\n';
}
// ========== IDS ==========
void IDS(int start, int goal, int maxDepth)
{
    for (int depth = 1; depth <= maxDepth; depth++)
    {
        vector<int> path;
        DLS(start, goal, depth, depth);
    }
}

// ========== UCS ==========
void UCS(int start, int goal)
{
    set<pair<int, int>> st;
    vector<int> cost(N, 999999), par(N, -1);
    cost[start] = 0;
    st.insert({0, start});
    cout << "UCS : ";

    while (!st.empty())
    {
        auto it = *st.begin();
        st.erase(st.begin());
        for (auto ch : graph[it.second])
        {
            if (cost[ch.first] > cost[it.second] + ch.second)
            {
                cost[ch.first] = cost[it.second] + ch.second;
                par[ch.first] = it.second;
                st.insert({cost[ch.first], ch.first});
            }
        }
    }
    for (int i = 1; i <= 5; i++)
        cout << par[i] << ' ';
    cout << '\n';
}

// ========== Bidirectional Search ==========
void Bidirectional(int start, int goal)
{
    queue<int> forward, backward;
    vector<int> visf(N, 0), visb(N, 0), parf(N, -1), parb(N, -1);
    visf[start] = visb[goal] = 1;
    forward.push(start);
    backward.push(goal);
    int last = -1;
    while (forward.size() && backward.size())
    {
        int sz = forward.size();
        while (sz--)
        {
            int t = forward.front();
            forward.pop();
            for (auto it : graph[t])
            {
                if (!visf[it.first])
                {
                    parf[it.first] = t;
                    if (visb[it.first])
                    {
                        last = it.first;
                        break;
                    }
                    forward.push(it.first);
                }
            }
            if (last != -1)
                break;
        }
        sz = backward.size();
        while (sz--)
        {
            int t = backward.front();
            backward.pop();
            for (auto it : graph[t])
            {
                if (!visb[it.first])
                {
                    parb[it.first] = t;
                    if (visf[it.first])
                    {
                        last = it.first;
                        break;
                    }
                    backward.push(it.first);
                }
            }
            if (last != -1)
                break;
        }
    }
    cout << "l" << last;
    cout << "Bidirectional : ";
    if (last == -1)
        cout << "NOT FOUND";
    else
    {
        int t = last;
        vector<int> path;
        while (last != -1)
        {
            path.push_back(last);
            last = parf[last];
        }
        reverse(path.begin(), path.end());
        for (auto it : path)
            cout << it << ' ';
        last = parb[t];
        while (last != -1)
        {
            cout << last << ' ';
            last = parb[last];
        }
    }
    cout << '\n';
}

// ========== A* ==========
int heuristic(int node, int goal)
{
    return abs(node - goal);
}
void Astar(int start, int goal)
{
    set<pair<int, int>> st;
    vector<int> cost(N, 9999999), h(N, 0), g(N, 9999), par(N, -1);
    g[start] = 0;
    h[start] = heuristic(start, goal);
    cost[start] = g[start] + h[start];
    st.insert({cost[start], start});
    cout << "A star : ";

    while (!st.empty())
    {
        auto it = *st.begin();
        st.erase(st.begin());
        for (auto ch : graph[it.second])
        {
            if (g[ch.first] > g[it.second] + ch.second)
            {
                g[ch.first] = g[it.second] + ch.second;
                h[ch.first] = heuristic(ch.first, goal);
                cost[ch.first] = g[ch.first] + h[ch.first];
                par[ch.first] = it.second;
                st.insert({cost[ch.first], ch.first});
            }
        }
    }
    for (int i = 1; i <= 5; i++)
        cout << par[i] << ' ';
    cout << '\n';
}

// ========== Driver ==========
int main()
{
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 4});
    graph[2].push_back({1, 1});
    graph[2].push_back({4, 2});
    graph[2].push_back({5, 4});
    graph[3].push_back({1, 4});
    graph[3].push_back({4, 1});
    graph[4].push_back({2, 2});
    graph[4].push_back({3, 1});
    graph[4].push_back({5, 1});
    graph[5].push_back({2, 3});
    graph[5].push_back({4, 1});

    int start = 1, goal = 5;

    BFS(start, goal);
    DFS(start, goal);
    DLS(start, goal, 2);
    IDS(start, goal, 5);
    UCS(start, goal);
    Bidirectional(start, goal);
    Astar(start, goal);
}
