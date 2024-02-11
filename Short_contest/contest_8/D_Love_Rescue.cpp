#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vvi = vector<vector<int>>;
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
    int *par, *rnk, N;
    bool *rm;
    int cc;

public:
    DSU(int n)
    {
        par = new int[n];
        rnk = new int[n];
        rm = new bool[n];
        cc = 0;

        for (int i = 0; i < n; i++)
            par[i] = i, rnk[i] = 1, rm[i] = false;
    }

    ~DSU()
    {
        delete[] par;
        delete[] rnk;
        delete[] rm;
    }

    int get(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = get(par[x]);
    }

    int unite(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 != p2)
        {
   	     if (rnk[p1] > rnk[p2])
    	    {
        	    par[p2] = p1;
            	rnk[p1] = max(rnk[p1], rnk[p2] + 1); // Rank based on height
       		}
	        else
    	    {
        	   par[p1] = p2;
 	           rnk[p2] = max(rnk[p2], rnk[p1] + 1);
    	    }
        	cc++;
    	}
    }
    
    int connected_cnt()
    {
    	return cc;
    }
}; 

void solve()
{
	int n; cin >> n;
	string v, t;
	cin >> v >> t;
	
	// map<char, int> freq;
	// ints
	DSU d(26);
    vector<char> fir(n), sec(n);
	for(int i = 0; i < n; i++)
	{
		int vch = v[i] - 'a', tch = t[i] - 'a';
        if (d.get(vch) != d.get(tch))
        {
            int cur = d.connected_cnt();
            fir[cur] = (char)('a' + d.get(vch));
            sec[cur] = (char)('a' + d.get(tch));    
        }
        
		d.unite(vch, tch);
	}
	cout << d.connected_cnt() << "\n";
    
    for(int i = 0; i < d.connected_cnt(); i++)
        cout << fir[i] << " " << sec[i] << "\n";
	
}

int main()
{
      FIO;
     int t = 1;
     // cin >> t;
     while(t--)
         solve();
     return 0;
}