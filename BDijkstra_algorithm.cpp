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
#define inf 90000000000000
#define MOD 1000000007
#define N 200009
//------------------------------------------------------------------------------------------
vector<pair<ll, ll>> g[N];
ll dis[N];
void dijkstra(ll a)
{
    multiset<pair<ll, ll>> st;
    st.insert({0, a});
    dis[a] = 0;
    while (!st.empty())
    {
        auto it = st.begin();
        ll nd = (*it).sc;
        st.erase(it);
        for (auto ch : g[nd])
        {
            if (dis[ch.fi] > dis[nd] + ch.sc)
            {
                dis[ch.fi] = dis[nd] + ch.sc;
                st.insert({ch.sc, ch.fi});
            }
        }
    }
}
void solve(void)
{
    ll n, m;
    cin >> n >> m;
    while (m--)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        g[x].ppb(y, w);
    }
    for (ll i = 1; i <= n; i++)
        dis[i] = inf;
    dijkstra(1);
    for (ll i = 1; i <= n; i++)
        cout << i << ' ' << dis[i] << '\n';
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