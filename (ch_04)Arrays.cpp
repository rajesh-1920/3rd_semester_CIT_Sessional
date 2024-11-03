// Author:  Rajesh Biswas
// CF    :  rajesh19
// Date  :  02.11.2024

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
void insert_at_position(ll a[], ll &sz, ll val, ll pos, ll MX_SZ) // al-4.1
{
    if (pos > sz + 1 || pos <= 0)
    {
        cout << "Invalid_position\n";
        return;
    }
    if (sz == MX_SZ)
    {
        cout << "Overflow\n";
        return;
    }
    ll i = sz;
    while (i >= pos)
    {
        a[i + 1] = a[i];
        i--;
    }
    a[pos] = val;
    sz++;
}
void traverse(ll a[], ll sz)
{
    if (sz == 0)
    {
        cout << "Empty array\n";
        return;
    }
    for (ll i = 1; i <= sz; i++)
        cout << a[i] << ' ';
    cout << '\n';
}
ll delete_at_position(ll a[], ll &sz, ll pos) // al-4.2
{
    if (sz == 0)
    {
        cout << "Underflow\n";
        return -1;
    }
    if (pos <= 0 || pos > sz)
    {
        cout << "Invalid position\n";
        return -1;
    }
    ll val = a[pos];
    while (pos < sz)
    {
        a[pos] = a[pos + 1];
        pos++;
    }
    sz--;
    return val;
}
ll linear_search(ll a[], ll sz, ll val)
{
    for (ll i = 1; i <= sz; i++)
    {
        if (a[i] == val)
            return i;
    }
    cout << "Not found ";
    return -1;
}
//------------------------------------------------------------------------------------------
void solve(void)
{
    ll n, MX_SZ = 100, sz = 0;
    printf("Enter the size of your array : ");
    cin >> n;
    ll a[MX_SZ + 1];
    printf("Enter value of your array : ");
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        insert_at_position(a, sz, x, i, MX_SZ);
    }
    while (true)
    {
        printf("What you want?\n 1->insert, 2->delete, 3->traverse, 4->search, -1->to end : ");
        ll qc;
        cin>>qc;
        if (qc == -1)
        {
            cout<<"Thank you\n";
            break;
        }
        if (qc == 1)
        {
            printf("Insert the position and value : ");
            ll pos, val;
            cin >> pos >> val;
            insert_at_position(a, sz, val, pos, MX_SZ);
        }
        if (qc == 3)
            traverse(a, sz);
        if (qc == 2)
        {
            printf("Insert the position : ");
            ll pos;
            cin >> pos;
            ll del = delete_at_position(a, sz, pos);
            if (del != -1)
                cout << "deleted value = " << del << '\n';
        }
        if (qc == 4)
        {
            printf("Insert the position : ");
            ll val;
            cin >> val;
            ll pos = linear_search(a, sz, val);
            if (pos != -1)
                cout << "Position = " << pos << '\n';
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
