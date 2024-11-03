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
class node
{
public:
    ll data;
    node *left;
    node *right;
    node(ll val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
//---------------------------(traverse)-----------------------------------------------------
void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
}
//------------------------------------------------------------------------------------------
ll search_position(ll in[], ll st, ll val)
{
    while (in[st] != val)
        st++;
    return st;
}
node *build_pre_in(ll pre[], ll in[], ll st, ll end)
{
    if (st > end)
        return NULL;
    static ll ind = 1;
    node *newnode = new node(pre[ind]);
    ll pos = search_position(in, st, pre[ind]);
    ind++;
    if (st == end)
        return newnode;
    newnode->left = build_pre_in(pre, in, st, pos - 1);
    newnode->right = build_pre_in(pre, in, pos + 1, end);
    return newnode;
}
node *build_post_in(ll post[], ll in[], ll st, ll end)
{
    if (st > end)
        return NULL;
    static ll ind = end;
    node *newnode = new node(post[ind]);
    ll pos = search_position(in, st, post[ind]);
    ind--;
    if (st == end)
        return newnode;
    newnode->right = build_post_in(post, in, pos + 1, end);
    newnode->left = build_post_in(post, in, st, pos - 1);
    return newnode;
}
//------------------------------------------------------------------------------------------
void solve(void)
{
    /*
    7
    1 2 4 5 3 6 7 -pre
    4 2 5 1 6 3 7 -in
    4 5 2 6 7 3 1 -post
    */
    // node *root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);
    // root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);
    // inorder(root);
    // postorder(root);
    // preorder(root);
    node *root = NULL;
    cout<<"Enter the number of nodes : ";
    ll n;
    cin >> n;
    cout<<"Enter the preorder arary : ";
    ll pre[n + 1], in[n + 1], post[n + 1];
    for (ll i = 1; i <= n; i++)
        cin >> pre[i];
    cout<<"Enter the inorder arary : ";
    for (ll i = 1; i <= n; i++)
        cin >> in[i];
    cout<<"Enter the postorder arary : ";
    for (ll i = 1; i <= n; i++)
        cin >> post[i];

    // root = build_pre_in(pre, in, 1, n);
    root = build_post_in(post, in, 1, n);

    preorder(root);
    //  postorder(root);
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
