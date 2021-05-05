       /****************#####       بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم       #####********************

        *********************       Saidur  Rahman        *************************
        *********************       CityU--CSE--47        *************************

--------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define         endl                "\n"
#define         EPS                 1e-6
#define         F                   first
#define         sf                  scanf
#define         pf                  printf
#define         S                   second
#define         die                 return 0
#define         MP                  make_pair
#define         pb                  push_back
#define         Do                  int main()
#define         PI                  acos(-1.0)
#define         NO                  cout<<"NO\n"
#define         No                  cout<<"No\n"
#define         no                  cout<<"no\n"
#define         YES                 cout<<"YES\n"
#define         Yes                 cout<<"Yes\n"
#define         yes                 cout<<"yes\n"
#define         sz(x)               int(x.size())
#define         all(a)              a.begin(),a.end()
#define         srt(x)              sort(x.begin(),x.end())
#define         clock_start         clock_t tStart = clock()
#define         MEM(a, b)           memset(a, (b), sizeof(a))         
#define         dbg(x)              cout << (#x) << " = " << (x) << endl
#define         Fast                ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define         dbg2(x, y)          cout << #x << " = " << x << " " << #y << " = " << y << endl
#define         dbg3(x, y, z)       cout << #x << " = " << x << " " << #y << " = " << y << " " << #z << " = " << z << endl
#define         show_time           cout<<"\n\nTime Taken: "<<fixed<<setprecision(3)<<(double)(clock() - tStart) /  CLOCKS_PER_SEC<<"s"
 

                     /******------- Some bit operations ------*****/
                     
long long     SetBit    (long long n, long long X)    { return n | (1LL << X); }//X-1 tomo bit 0 hole 1 korbe, 1 hole unchange
long long     ClearBit  (long long n, long long X)    { return n & ~(1LL << X); }//X-1 tomo bit 1 hole 0 korbe, 0 hole unchange
long long     ToggleBit (long long n, long long X)    { return n ^ (1LL << X); }//X-1 tomo bit 1 hole 0 korbe r 0 hole 1
bool          CheckBit  (long long n, long long X)    { return (bool)(n & (1LL << X)); }//X-1 tomo bit 1 naki 0 bolbe
 

                    /*******-----------Graph Moves------------*****/ 

const   int     dx[] = {1, -1, 0, 0};
const   int     dy[] = {0, 0, 1, -1};

const   int     kx[] = {-2, -2, -1, -1, 1, 1, 2, 2};      // Knights Move
const   int     ky[] = {-1, 1, -2, 2, -2, 2, -1, 1};     // Knights Move

const   int     Kx[] = {0, 0, 1, -1, -1, 1, -1, 1};     // Kings Move
const   int     Ky[] = {-1, 1, 0, 0, 1, 1, -1, -1};    // Kings Move

                   /*--------------------------------------------*/



            ///////////////////////////////////////////////////////////////////////////
        ///////////////////////// DO NOT TOUCH BEFORE THIS LINE //////////////////////////
            //////////////////////////////////////////////////////////////////////////


 
typedef     long long   ll;
typedef     pair<int,int>pi;
typedef     pair<ll,ll>pll;
const       int MAX  = 1e5 + 5;
const       int MOD  = 1e9 + 7;
const       int INF  = 1e9;
const       ll LINF  = 1e18;

int a[MAX], n;
int tree[MAX * 4];
void tree_build(int node,int l, int h)
{
    if(l==h)
    {
        tree[node] = a[l];
        return;
    }
    
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + h) / 2;
    tree_build(left, l, mid);
    tree_build(right, mid + 1, h);
    tree[node] = tree[left] + tree[right];

}

int query(int node,int l,int h,int i,int j)
{
    if(l>j || h<i)
        return 0;
    if(l>=i && h<=j)
    {
        return tree[node];
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + h) / 2;
    int s1 = query(left, l, mid, i, j);
    int s2 = query(right, mid+1, h, i, j);
    return s1 + s2;
}

void update(int node,int l,int h,int i,int new_value)
{
    if(l>i || h<i)
        return;

    if(l>=i && h<=i)
    {
        tree[node] = new_value;
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + h) / 2;
    update(left, l, mid, i, new_value);
    update(right, mid + 1, h, i, new_value);
    tree[node] = tree[left] + tree[right];
}

Do
{
    Fast;

#ifndef ONLINE_JUDGE
    clock_start;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin>>n;

    for (int i = 1; i <= n;i++)
        cin >> a[i];

    tree_build(1, 1, n);

    for (int i = 1; i <= 4 * n;i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;

    int x, y;
    cin >> x >> y;
    cout << query(1, 1, n, x, y) << endl;

    cin >> x >> y;
    update(1, 1, n, x, y);

    for (int i = 1; i <= 4 * n; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;

    cin >> x >> y;
    cout << query(1, 1, n, x, y) << endl;

#ifndef ONLINE_JUDGE 
    show_time;
#endif

    die;
}
