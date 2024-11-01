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
void solve(void)
{
    ll n;
    cin >> n;
    ll a[n + 1];
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
    {
        ll temp = a[i];
        ll j = i - 1;
        while (j >= 1 && temp < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
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