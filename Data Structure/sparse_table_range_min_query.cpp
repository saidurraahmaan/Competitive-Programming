#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
const int k = 25;
int arr[MAX];
int table[MAX][k];

void display(int a[][25], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void precompute(int n)
{
    for (int i = 0; i < n; i++)
        table[i][0] = arr[i];

    for (int j = 1; j < 4; j++)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
        {
            int x = i + (1 << (j - 1));
            table[i][j] = table[i][j - 1] + table[x][j - 1];
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    precompute(n);

    int q;
    cin >> q;
    int lg = ceil(log2(n));
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        r--, l--;
        for (int j = lg; j >= 0; j--)
        {
            if ((1 << j) <= r - l + 1)
            {
                ans += table[l][j];
                l += 1 << j;
            }
        }

        cout << ans << endl;
    }
}
