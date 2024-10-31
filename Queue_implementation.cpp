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
void PUSH(ll que[], ll &front, ll &rear, ll mx_sz, ll val)
{
    if (front == rear + 1 || (front == 1 && rear == mx_sz)) // rear e add hobe
    {
        cout << "Overflow\n";
        return;
    }
    if (front == 0)
        front = rear = 1;
    else if (rear == mx_sz)
        rear = 1;
    else
        rear = rear + 1;
    que[rear] = val;
}
void traverse(ll que[], ll front, ll rear, ll mx_sz)
{
    if (front == 0)
    {
        cout << "Empty queue\n";
        return;
    }
    while (true)
    {
        if (front == rear)
        {
            cout << que[front] << '\n';
            return;
        }
        cout << que[front] << ' ';
        if (front == mx_sz)
            front = 1;
        else
            front++;
    }
}
void POP(ll que[], ll &front, ll &rear, ll mx_sz)
{
    if (front == 0)
    {
        cout << "Underflow\n";
        return;
    }
    cout << "Popped value = " << que[front] << '\n';
    if (front == rear)
        front = rear = 0;
    else if (front == mx_sz)
        front = 1;
    else
        front = front + 1;
}
//------------------------------------------------------------------------------------------
void solve(void)
{
    ll n, mx_sz = 5, front = 0, rear = 0;
    cin >> n;
    ll que[mx_sz + 1];
    f(i, 1, n)
    {
        ll x;
        cin >> x;
        // PUSH(que, front, rear, mx_sz, x);
    }
    PUSH(que, front, rear, mx_sz, 2);
    traverse(que, front, rear, mx_sz);
    POP(que, front, rear, mx_sz);
    traverse(que, front, rear, mx_sz);
    POP(que, front, rear, mx_sz);
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