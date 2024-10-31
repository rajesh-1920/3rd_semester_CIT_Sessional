// Author:  Rajesh Biswas
// CF    :  rajesh19
// Date  :  31.10.2024

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
void tower(ll n, char beg, char aux, char end)
{
    if (n == 1)
    {
        cout << beg << " -> " << end << '\n';
        return;
    }
    tower(n - 1, beg, end, aux);
    cout << beg << " -> " << end << '\n';
    tower(n - 1, aux, beg, end);
}
void solve(void)
{
    ll n;
    cin >> n;
    tower(n, 'A', 'B', 'C');
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