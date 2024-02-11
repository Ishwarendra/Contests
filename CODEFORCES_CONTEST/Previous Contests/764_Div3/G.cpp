#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};
// #define int long long

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};


class DSU
{
    int *par; int *rnk;
public:
    DSU(int n)
    {
        par = new int[n];
        rnk = new int[n];

        for(int i = 0; i < n; i++)
            par[i] = i, rnk[i] = 1;
    }

    ~DSU()
    {
        delete[] par;
        delete[] rnk;
    }

    int get(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = get(par[x]);
    }

    void unite(int x, int y)
    {
        x = get(x), y = get(y);
        if (x != y)
        {
            if (rnk[x] < rnk[y])
                par[x] = y, rnk[y] += rnk[x];
            else
                par[y] = x, rnk[x] += rnk[y];
        }
    }
};

int getBit(int x, int pos)
{
    if (x == 0)
        return 0;
    return ((x & (1 << pos)) != 0);
}

int setBit(int x, int pos)
{
    x = (x | (1 << pos));
    return x;
}

struct edge{
    int u, v, w;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<edge> edg(m);
    for(int i = 0; i < m; i++)
    {
        edge e;
        cin >> e.u >> e.v >> e.w;
        e.u--, e.v--;
        edg[i] = e;
    }

    // max ans = 10^9
    // 2^29 = 9 bits, 2^30 = 10 bits 
    int ans = 0;
    for(int pos = 29; pos >= 0; pos--)
    {
        DSU d(n);
        // int cur_bit = getBit(ans, pos);
        int cur_val = ans + (1 << pos);

        for(int i = 0; i < m; i++)
        {
            if ((edg[i].w & cur_val) == 0) 
                d.unite(edg[i].u, edg[i].v);
        }

        bool connected = true;
        for(int i = 0; i < n - 1; i++)
        {
            if (d.get(i) != d.get(i + 1))   
                connected = false;
        }

        if (!connected)
            ans = cur_val;
        // print(pos, 1 << pos, ans, cur_val);
    }

    // bit wise complement
    cout << ans << "\n";
}

int32_t main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}