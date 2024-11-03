// Author:  Rajesh Biswas
// CF    :  rajesh19
// Date  :  01.11.2024

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
ll a[N];
void merge(ll l, ll r)
{
    ll m = (l + r) / 2;
    ll a1[m - l + 5], a2[r - m + 5];
    ll lf = 0, rf = 0;
    for (ll i = l; i <= m; i++)
        a1[lf++] = a[i];
    a1[lf] = LONG_LONG_MAX;
    for (ll i = m + 1; i <= r; i++)
        a2[rf++] = a[i];
    a2[rf] = LONG_LONG_MAX;
    lf = rf = 0;
    for (ll i = l; i <= r; i++)
    {
        if (a1[lf] < a2[rf])
            a[i] = a1[lf++];
        else
            a[i] = a2[rf++];
    }
}
void merge_sort(ll l, ll r)
{
    if (l == r)
        return;
    merge_sort(l, (l + r) / 2);
    merge_sort((l + r) / 2 + 1, r);
    merge(l, r);
}
void solve(void)
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    merge_sort(1, n);
    for (ll i = 1; i <= n; i++)
        cout << a[i] << ' ';
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