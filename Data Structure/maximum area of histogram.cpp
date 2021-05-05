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
#define         done                return 0
#define         MP                  make_pair
#define         pb                  push_back
#define         start               int main()
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
 

                     /****** Template of some bit operations *****/
                     
long long     SetBit    (long long n, long long X)    { return n | (1LL << X); }//X-1 tomo bit 0 hole 1 korbe, 1 hole unchange
long long     ClearBit  (long long n, long long X)    { return n & ~(1LL << X); }//X-1 tomo bit 1 hole 0 korbe, 0 hole unchange
long long     ToggleBit (long long n, long long X)    { return n ^ (1LL << X); }//X-1 tomo bit 1 hole 0 korbe r 0 hole 1
bool          CheckBit  (long long n, long long X)    { return (bool)(n & (1LL << X)); }//X-1 tomo bit 1 naki 0 bolbe
 

            ///////////////////////////////////////////////////////////////////////////
        ///////////////////////// DO NOT TOUCH BEFORE THIS LINE //////////////////////////
            //////////////////////////////////////////////////////////////////////////
 
 
typedef     long long   ll;
const       int MAX  = 1e5 + 5;
const       int MOD  = 1e9 + 7;
const       int INF  = 1e9;
const       ll LINF  = 1e18;



void display(stack<int>s)
{
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

start
{
    Fast;

#ifndef ONLINE_JUDGE
    clock_start;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin>>n;
    int arr[n];
    for (int i = 0;i<n;i++){
        cin >> arr[i];
    }
    stack<int> s;
    int ans = 0;
    int tp;
    int area_with_top;
    int i = 0;
    while (i<n){
        if(s.empty() || arr[s.top()]<=arr[i]){
            s.push(i++);
        }
        else{
            tp = s.top();
            s.pop();
            area_with_top = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            ans = max(ans, area_with_top);
        }
       // display(s);
    }

    while(!s.empty()){
        tp = s.top();
        s.pop();
        area_with_top = arr[tp] * (s.empty() ? i : i - s.top() - 1);
        ans = max(ans, area_with_top);
    }
    cout << ans << endl;

#ifndef ONLINE_JUDGE 
    show_time;
#endif

    done;
}