#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

int arr[MAX];
int tree[4 * MAX], lazy[4 * MAX];

void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }
    int mid = (b + e) / 2;
    build(node * 2, b, mid);
    build(node * 2 + 1, mid + 1, e);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node,int b,int e,int l,int r,int val)
{
    if(lazy[node]!=0)
    {
        int dx = lazy[node];
        lazy[node] = 0;
        tree[node] += dx * (e - b + 1);

        if(b!=e)
        {
            lazy[node * 2] += dx;
            lazy[node * 2 + 1] += dx;
        }
    }

    if(b>r || e<l)
        return;

    if(b>=l && e<=r)
    {
        int dx = (e - b + 1) * val;
        tree[node] += dx;

        if(b!=e)
        {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }

    int mid = (b + e) / 2;
    update(node * 2, b, mid, l, r, val);
    update(node * 2 + 1, mid + 1, e, l, r, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node,int b,int e,int l,int r)
{
    if(lazy[node]!=0)
    {
        int dx = lazy[node];
        lazy[node] = 0;
        tree[node] += dx * (e - b + 1);

        if(b!=e)
        {
            lazy[node * 2 ] += dx;
            lazy[node * 2 + 1] += dx;
        }
    }

    if(b>r || e<l)
        return 0;

    if(b>= l && e<=r)
        return tree[node];

    int mid = (b + e) / 2;
    int s1 = query(node * 2, b, mid, l, r);
    int s2 = query(node * 2 + 1, mid + 1, e, l, r);

    return s1 + s2;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n;i++)
        cin >> arr[i];

    build(1, 1, n);

    while(q--)
    {
        int type, l, r, x;
        cin >> type;
        if(type==1)
        {
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        }
        else
        {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
}
