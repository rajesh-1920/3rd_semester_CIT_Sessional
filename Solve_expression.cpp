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
ll binexpo(ll A, ll B)
{
    ll ans = 1;
    while (B)
    {
        if (B & 1)
            ans *= A;
        A *= A;
        B >>= 1;
    }
    return ans;
}
ll string_to_int(string s)
{
    ll ans = 0;
    for (ll i = 0; i < s.size(); i++)
        ans = (ans * 10) + s[i] - '0';
    return ans;
}
//------------------------------------------------------------------------------------------
ll postfix_to_ans(vector<string> postfix)
{
    stack<ll> st;
    for (auto it : postfix)
    {
        if (it == "+")
        {
            ll t1 = st.top();
            st.pop();
            ll t2 = st.top();
            st.pop();
            st.push(t2 + t1);
        }
        else if (it == "-")
        {
            ll t1 = st.top();
            st.pop();
            ll t2 = st.top();
            st.pop();
            st.push(t2 - t1);
        }
        else if (it == "*")
        {
            ll t1 = st.top();
            st.pop();
            ll t2 = st.top();
            st.pop();
            st.push(t2 * t1);
        }
        else if (it == "/")
        {
            ll t1 = st.top();
            st.pop();
            ll t2 = st.top();
            st.pop();
            st.push(t2 / t1);
        }
        else if (it == "^")
        {
            ll t1 = st.top();
            st.pop();
            ll t2 = st.top();
            st.pop();
            st.push(binexpo(t2, t1));
        }
        else
        {
            ll temp = string_to_int(it);
            st.push(temp);
        }
    }
    return st.top();
}
vector<string> infix_to_postfix(vector<string> infix)
{
    stack<string> st;
    st.push("(");
    infix.push_back(")");
    vector<string> postfix;
    for (auto it : infix)
    {
        if (it == "(")
            st.push(it);
        else if (it == ")")
        {
            while (st.top() != "(")
            {
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if (it == "^")
            st.push(it);
        else if (it == "*" || it == "/")
        {
            while (st.top() != "+" && st.top() != "-" && st.top() != "(")
            {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(it);
        }
        else if (it == "+" || it == "-")
        {
            while (st.top() != "(")
            {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(it);
        }
        else
            postfix.push_back(it);
    }
    return postfix;
}
//------------------------------------------------------------------------------------------
void solve(void)
{
    vector<string> postfix, prefix, infix;
    string s;
    while (cin >> s)
        infix.push_back(s);
    postfix = infix_to_postfix(infix);
    for (auto it : postfix)
        cout << it << ' ';
    cout << '\n';
    cout << postfix_to_ans(postfix);
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