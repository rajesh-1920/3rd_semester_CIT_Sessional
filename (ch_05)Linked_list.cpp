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

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

#define PI acos(-1)
#define base1 1000002089
#define base2 1000003853
#define hashmod 1000002989

#define eps 0.0000000001
#define inf 90000000000000
#define MOD 1000000007
#define N 200009
//------------------------------------------------------------------------------------------
class node
{
public:
    ll data;
    node *next;
    node(ll val)
    {
        data = val;
        next = NULL;
    }
};
//--------------------traverse--------------------------------------------------------------
void traverse(node *head) // al-5.1
{
    if (head == NULL)
    {
        cout << "Empty list\n";
        return;
    }
    while (head != NULL)
    {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << '\n';
}
bool search(node *head, ll val)
{
    while (head != NULL)
    {
        if (head->data == val)
            return true;
        head = head->next;
    }
    return false;
}
ll search_position(node *head, ll val) // al-5.2
{
    if (!search(head, val))
    {
        cout << "The value is not present\n";
        return -1;
    }
    ll pos = 0;
    while (head != NULL)
    {
        pos++;
        if (head->data == val)
            return pos;
        head = head->next;
    }
}
//------------------------------------------------------------------------------------------
//------------inseartion--------------------------------------------------------------------
void insert_at_begin(node *&head, ll val) // al-5.4
{
    node *newnode = new node(val);
    newnode->next = head;
    head = newnode;
}
void insert_at_end(node *&head, ll val)
{
    node *newnode = new node(val);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    newnode->next = temp->next;
    temp->next = newnode;
}
void insert_at_position(node *&head, ll val, ll pos) // al-5.5
{
    if (pos < 1)
    {
        cout << "Invalid position\n";
        return;
    }
    if (pos == 1)
    {
        insert_at_begin(head, val);
        return;
    }
    node *newnode = new node(val);
    node *temp = head;
    ll cnt = 1;
    while (temp->next != NULL && cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        cout << "Invalid position\n";
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
//------------------------------------------------------------------------------------------
//------------------Delation----------------------------------------------------------------
ll delete_at_begin(node *&head) // al-5.8
{
    if (head == NULL)
    {
        cout << "Underflow\n";
        return -1;
    }
    node *todelete = head;
    head = head->next;
    ll val = todelete->data;
    delete todelete;
    return val;
}
ll delete_at_end(node *&head)
{
    if (head == NULL)
    {
        cout << "Underflow\n";
        return -1;
    }
    node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    node *to_delete = temp->next;
    temp->next = temp->next->next;
    ll val = to_delete->data;
    delete to_delete;
    return val;
}
ll delete_by_value(node *&head, ll val) // al-5.10
{
    bool is_present = search(head, val);
    if (!is_present)
    {
        cout << "The value is not present in the list\n";
        return -1;
    }
    node *temp = head;
    while (temp->next->data != val)
        temp = temp->next;
    node *to_delete = temp->next;
    temp->next = temp->next->next;
    delete to_delete;
    return val;
}
ll delete_by_pos(node *&head, ll pos)
{
    if (head == NULL)
    {
        cout << "Underflow\n";
        return -1;
    }
    if (pos == 1)
        return delete_at_begin(head);
    node *temp = head;
    ll cnt = 1;
    while (temp->next != NULL && cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        cout << "Invalid Position\n";
        return -1;
    }
    node *to_delete = temp->next;
    temp->next = temp->next->next;
    ll val = to_delete->data;
    delete to_delete;
    return val;
}
//------------------------------------------------------------------------------------------
void solve(void)
{
    ll n;
    cin >> n;
    node *head = NULL;
    f(i, 0, n)
    {
        ll x;
        cin >> x;
        insert_at_end(head, x);
    }
    // insert_at_begin(head, 10);
    // insert_at_position(head, 15, 4);
    // cout << search(head, 3) << '\n';
    traverse(head);
    // cout << delete_at_begin(head) << '\n';
    // cout << delete_at_end(head) << '\n';
    // cout << delete_by_value(head, 6) << '\n';
    // cout << delete_by_pos(head, 6) << '\n';
    // traverse(head);
    cout << search_position(head, 6);
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