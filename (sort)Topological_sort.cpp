// Author:  Rajesh Biswas
// CF    :  rajesh19
// Date  :  04-11-2024

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//----------------------------(definition section)------------------------------------------
#define f(i, a, b) for (ll i = a; i < b; i++)
#define scv(v, n) f(i, 0, n) cin >> (v[i]);
#define dbg(x) cout << #x << " = " << x << '\n'
#define nl cout << ("\n")
#define rrr return
#define fi first
#define sc second
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
#define all(x) x.begin(), x.end()

#define inf 90000000000000
#define N 200009
//------------------------------------------------------------------------------------------
vector<ll> g[N], topo;
ll vis[N], cycle;
void dfs(ll n)
{
    vis[n] = 1;
    for (auto it : g[n])
    {
        if (vis[it] == 1)
            cycle = 1;
        if (vis[it] == 0)
            dfs(it);
    }
    vis[n] = 2;
    topo.push_back(n);
}
void solve(void)
{
    ll n, m;
    cin >> n >> m;
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    cycle = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i);
    }
    reverse(all(topo));
    if (cycle == 1)
        cout << "Cycle exist .";
    else
    {
        cout << "The topological sortest list : ";
        for (auto it : topo)
            cout << it << ' ';
    }
}
//------------------------------------------------------------------------------------------
int main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
/*
freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
*/