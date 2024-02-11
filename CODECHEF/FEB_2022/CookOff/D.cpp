#include <bits/stdc++.h>
using namespace std;

#define FIO        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)     ((a).begin()), ((a).end())
#define printarr   (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using maxheap  =    priority_queue<int>;
using minheap  =    priority_queue<int, vector<int>, greater<int>>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

void solve()
{
	int n, m;
    cin >> n >> m;
    
    int sum = 0LL;
    
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        sum += x;
    }
    
    sum -= (n*(n - 1))/2;
    
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v; //usels       
    }
    
    int q; cin >> q;
    
    while(q--)
    {
        char ch; cin >> ch;
        
        if (ch == '?')
            cout << sum + 2*m << "\n";
        else if (ch == '-')
        {
            int u, v; cin >> u >> v;
            m--;
        }
        else
        {
            int u, v; cin >> u >> v;
            m++;
        }
    }
    
}

int32_t main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}