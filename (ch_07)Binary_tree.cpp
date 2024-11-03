// Author:  Rajesh Biswas
// CF    :  rajesh19
// Date  :  02-11-2024

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

#define inf 90000000000000
#define N 200009
//------------------------------------------------------------------------------------------
ll a[N], tree[4 * N];
void init(ll n, ll l, ll r)
{
    if (l == r)
    {
        tree[n] = a[l];
        return;
    }
    ll m = (l + r) / 2;
    init(n * 2, l, m);
    init(n * 2 + 1, m + 1, r);
    tree[n] = tree[n * 2] + tree[n * 2 + 1];
}
ll result(ll n, ll l, ll r, ll myl, ll myr)
{
    if (myl > myr)
        return 0;
    if (l == myl && r == myr)
        return tree[n];
    ll m = (l + r) / 2;
    ll ans1 = result(n * 2, l, m, myl, min(m, myr));
    ll ans2 = result(n * 2 + 1, m + 1, r, max(m + 1, myl), myr);
    return ans1 + ans2;
}
//------------------------------------------------------------------------------------------
void solve(void)
{
    ll n, q;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    init(1, 1, n);
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        cout << result(1, 1, n, x, y) << '\n';
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