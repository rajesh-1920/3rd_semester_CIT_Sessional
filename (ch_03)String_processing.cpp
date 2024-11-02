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
ll position_of_pattern(string s, string p) // al-3.3
{
    ll i = 0;
    ll sz_s = s.size(), sz_p = p.size();
    while (i < (sz_s - sz_p + 1))
    {
        ll j = 0;
        while (j < sz_p)
        {
            if (s[i + j] != p[j])
                break;
            j++;
        }
        if (j == sz_p)
            return i;
        i++;
    }
    return -1;
}
string delete_every_pattern(string s, string p) // al-3.1
{
    while (true)
    {
        ll pos = position_of_pattern(s, p);
        if (pos == -1)
            break;
        if (pos == 0 && s.size() == p.size())
            return "EMPTY_STRING";

        string temp;
        for (ll i = 0; i < pos; i++)
            temp.push_back(s[i]);
        ll i = 0, last = 0;
        while (i < p.size() && pos + i + p.size() < s.size())
        {
            temp.push_back(s[pos + i + p.size()]);
            last = pos + i + p.size();
            i++;
        }
        i = last + 1;
        while (i < s.size() && last != 0)
        {
            temp.push_back(s[i]);
            i++;
        }
        s = temp;
    }
    return s;
}
string replace_every_occur(string s, string p, string q) // al-3.2
{
    if (p == q)
        return s;
    ll pos = position_of_pattern(p, q);
    if (pos != -1)
        return "Invalid replacement....Time out\n";
    while (true)
    {
        ll pos = position_of_pattern(s, p);
        if (pos == -1)
            return s;
        string temp;
        for (ll i = 0; i < pos; i++)
            temp.push_back(s[i]);
        for (ll i = 0; i < q.size(); i++)
            temp.push_back(q[i]);
        ll i = 0, last = 0;
        while (i < p.size() && i + pos + p.size() < s.size())
        {
            temp.push_back(s[pos + p.size() + i]);
            last = i + p.size() + pos;
            i++;
        }
        i = last + 1;
        while (i < s.size() && last != 0)
        {
            temp.push_back(s[i]);
            i++;
        }
        s = temp;
    }
}
void solve(void)
{
    string s;
    cin >> s;
    s = replace_every_occur(s, "a", "A");
    s = replace_every_occur(s, "e", "E");
    s = replace_every_occur(s, "i", "I");
    s = replace_every_occur(s, "o", "O");
    s = replace_every_occur(s, "u", "U");
    cout << s << '\n';
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