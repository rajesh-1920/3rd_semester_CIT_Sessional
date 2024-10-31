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
//-------------------------------------------------------------------------------------------
void PUSH(ll stk[], ll mx_stk, ll &top, ll val)
{
    if (top == mx_stk)
    {
        cout << "Overflow\n";
        return;
    }
    top = top + 1;
    stk[top] = val;
}
void pop(ll stk[], ll &top)
{
    if (top == 0)
    {
        cout << "Underflow\n";
        return;
    }
    cout << "Popped value = " << stk[top] << '\n';
    top = top - 1;
}
void traverse(ll stk[], ll top)
{
    if (top == 0)
    {
        cout << "Empty stack\n";
        return;
    }
    while (top)
    {
        cout << stk[top] << ' ';
        top--;
    }
    cout << '\n';
}
//-------------------------------------------------------------------------------------------
void solve(void)
{
    ll n;
    cin >> n;
    ll max_stk = 5, top = 0;
    ll stk[max_stk + 1];
    f(i, 0, n)
    {
        ll x;
        cin >> x;
        PUSH(stk, max_stk, top, x);
    }
    traverse(stk, top);
    pop(stk, top);
    traverse(stk, top);
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