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
void solve(void)
{
    ll r1, c1, r2, c2;
    cin >> r1 >> c1;
    ll a1[r1][c1];
    for (ll i = 0; i < r1; i++)
        for (ll j = 0; j < c1; j++)
            cin >> a1[i][j];
    cin >> r2 >> c2;
    ll a2[r2][c2];
    for (ll i = 0; i < r2; i++)
        for (ll j = 0; j < c2; j++)
            cin >> a2[i][j];
    if (c1 != r2)
    {
        cout << "Invalid dimenssion\n";
        return;
    }
    ll ans[r1][c2];
    for (ll i = 0; i < r1; i++)
        for (ll j = 0; j < c2; j++)
        {
            ans[i][j] = 0;
            for (ll k = 0; k < c1; k++)
            {
                ans[i][j] += a1[i][k] * a2[k][j];
                //dbg(a2[k][j]);
            }
        }
    for (ll i = 0; i < r1; i++)
    {
        for (ll j = 0; j < c2; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
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