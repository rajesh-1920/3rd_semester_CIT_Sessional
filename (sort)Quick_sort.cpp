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
ll quick(ll lf, ll rf)
{
    ll loc = lf;
    while (true)
    {
        while (a[rf] >= a[loc] && loc != rf)
            rf--;
        if (loc == rf)
            return loc;
        swap(a[loc], a[rf]);
        loc = rf;

        while (a[lf] <= a[loc] && loc != lf)
            lf++;
        if (lf == loc)
            return loc;
        swap(a[loc], a[lf]);
        loc = lf;
    }
}
void quicksort(ll l, ll r)
{
    stack<ll> left, right;
    left.push(l);
    right.push(r);
    while (!right.empty())
    {
        l = left.top(), r = right.top();
        left.pop(), right.pop();
        ll m = quick(l, r);
        if (m - 1 > l)
            left.push(l), right.push(m - 1);
        if (r > m + 1)
            left.push(m + 1), right.push(r);
    }
}
void solve(void)
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    quicksort(1, n);
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