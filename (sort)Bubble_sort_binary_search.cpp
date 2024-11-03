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
ll binary_search_v(vector<ll> v, ll value)
{
    if (v.size() == 0)
    {
        cout << "Empty\n";
        return -1;
    }
    ll l = 0, r = v.size() - 1;
    while (r - l > 1)
    {
        ll m = (r + l) / 2;
        if (v[m] == value)
            return m;
        else if (v[m] > value)
            r = m - 1;
        else
            l = m + 1;
    }
    if (v[r] == value)
        return r;
    if (v[l] == value)
        return l;
    return -1;
}
//------------------------------------------------------------------------------------------
void solve(void)
{
    ll n;
    cout<<"Enter The size of your array : ";
    cin >> n;
    vector<ll> v(n);
    cout<<"Enter The value of your array : ";
    for (auto &it : v)
        cin >> it;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n - i; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
    while(true)
    {
        cout<<"Enter The value (-1->to end) you want to search: ";
        ll val;
        cin>>val;
        if(val==-1)
            break;
        ll is = binary_search_v(v, val);
        if (is == -1)
            cout << "Notfound\n";
        else
        {
            cout << "Founded\n";
            cout << "Pos = " << is + 1 << '\n';
        }
    }
}
//------------------------------------------------------------------------------------------
int main()
{
    // cout << fixed << showpoint << setprecision(10);
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/
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
