// Author:  Rajesh Biswas
// CF    :  rajesh19
// Date  :  30.10.2024

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//------------------------------------------------------------------------------------------
/*/----------------------------(Order_set)--------------------------------------------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
o_set<ll> s;
//---------------------------------------------------------------------------------------*/
/*/-------------------------Modular-Arithmatic----------------------------------------------
inline ll _normal(ll A, ll M)
{
    A = A - (A / M) * M;
    if (A < 0)
        A += M;
    return A;
}
inline ll modadd(ll A, ll B, ll M)
{
    A = _normal(A, M), B = _normal(B, M);
    return _normal(A + B, M);
}
inline ll modsub(ll A, ll B, ll M)
{
    A = _normal(A, M), B = _normal(B, M);
    return _normal(A - B, M);
}
inline ll modmul(ll A, ll B, ll M)
{
    A = _normal(A, M), B = _normal(B, M);
    return _normal(A * B, M);
}
inline ll binexpo(ll A, ll B, ll M)
{
    ll ans = _normal(1, M);
    while (B)
    {
        if (B & 1)
            ans = modmul(ans, A, M);
        A = modmul(A, A, M);
        B >>= 1;
    }
    return _normal(ans, M);
}
inline ll moddiv(ll A, ll B, ll M)
{
    A = _normal(A, M), B = _normal(B, M);
    return _normal(modmul(A, (binexpo(B, M - 2, M)), M), M);
}
//-----------------------------------------------------------------------------------------*/
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

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

#define PI acos(-1)
#define base1 1000002089
#define base2 1000003853
#define hashmod 1000002989

#define eps 0.0000000001
#define MOD 1000000007
#define inf 9000000000000
#define N 200009
//------------------------------------------------------------------------------------------
void solve(void)
{
    ll n, m;
    cin >> n >> m;
    ll path[n + 5][n + 5], dis[n + 5][n + 5];
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
        {
            path[i][j] = i == j ? 1 : 0;
            dis[i][j] = i == j ? 0 : inf;
        }
    while (m--)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        dis[x][y] = dis[y][x] = w;
        path[x][y] = path[y][x] = 1;
    }

    for (ll k = 1; k <= n; k++)
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= n; j++)
            {
                path[i][j] = path[i][j] | (path[i][k] && path[k][j]);
                dis[i][j] = min(dis[i][j], (dis[i][k] + dis[k][j]));
            }
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
        {
            if (path[i][j] == 1)
            {
                cout << "Path exist between " << i << " and " << j << '\n';
                cout << "Minimum distance = " << dis[i][j] << '\n';
            }
            else
                cout << "No path exist between " << i << " and " << j << '\n';
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