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
    string s; cin >> s;
    
    // rgb
    vi key = {0, 0, 0};
    vi door = {0, 0, 0};
    
    map<int, int> m;
    
    m['r'] = 0, m['R'] = 0;
    m['g'] = 1, m['G'] = 1;
    m['b'] = 2, m['B'] = 2;
    
    
    for(int i = 0; i < 6; i++)
    {
        // door encounter
        if (s[i] - 'a' < 0)
        {
            if (not key[m[s[i]]])
            {
                cout << "NO\n";
                return;
            }
        }
        
        // key encountered
        else
            key[m[s[i]]] = 1;
    }
    
    cout << "YES\n";
}

int32_t main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}