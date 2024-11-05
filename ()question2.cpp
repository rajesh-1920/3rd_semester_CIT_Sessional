// Author:  Rajesh Biswas
// CF    :  rajesh19
// Date  :  04-11-2024

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//----------------------------(definition section)------------------------------------------
#define inf 90000000000000
#define N 200009
//------------------------------------------------------------------------------------------
vector<ll> g[N];
void insert_edge(char nod, char ch)
{
    ll node = nod - 'A' + 1;
    ll child = ch - 'A' + 1;
    g[node].push_back(child);
}
void insert_node(ll nod)
{
    ll node = nod - 'A' + 1;
    ll child = 'a' - 'A' + 1;
    if(g[node].size()>=1)
        return;
    g[node].push_back(child);
}
void traverse()
{
    for (ll i = 1; i <= 26; i++)
    {
        for (auto it : g[i])
        {
            char pr = char(i - 1 + 'A');
            char chi = char(it - 1 + 'A');
            if (chi == 'a')
            {
                if (g[i].size() == 1)
                    cout << pr << '\n';
            }
            else
                cout << pr << " -> " << chi << '\n';
        }
    }
    cout << "\n";
}
bool find_edge(char par, char child)
{
    for (ll i = 1; i <= 26; i++)
    {
        for (auto it : g[i])
        {
            char pr = char(i - 1 + 'A');
            char chi = char(it - 1 + 'A');
            if (par == pr && chi == child)
                return true;
        }
    }
    return false;
}
void solve(void)
{
    cout << "Insert the number of nodes and edge of the initial graph : ";
    ll n, m;
    cin >> n >> m;
    cout << "Insert all edges :\n";
    while (m--)
    {
        char ch1, ch2;
        cin >> ch1 >> ch2;
        insert_edge(ch1, ch2);
    }
    while (true)
    {
        cout << "What you want ?\n ";
        cout << "1->insert_node, 2->insert_edge, 3->search_edge, 4->traverse, -1->to_exit : ";
        ll t;
        cin >> t;
        if (t == -1)
        {
            cout << "Thank you\n";
            break;
        }
        if (t == 4)
            traverse();
        if (t == 1)
        {
            cout << "Enter the node : ";
            char ch;
            cin >> ch;
            insert_node(ch);
        }
        if (t == 2)
        {
            cout << "Enter the parent and child of the inserting edge : ";
            char ch1, ch2;
            cin >> ch1 >> ch2;
            insert_edge(ch1, ch2);
        }
        if (t == 3)
        {
            cout << "Enter the parent and child of the finding edge : ";
            char ch1, ch2;
            cin >> ch1 >> ch2;
            bool fl = find_edge(ch1, ch2);
            if (fl)
                cout << "Edge founded\n";
            else
                cout << "Edge not found\n";
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
