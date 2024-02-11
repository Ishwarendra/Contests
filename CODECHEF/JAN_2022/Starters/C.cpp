#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
// using vll = vector<long long>;
// using ll = long long;
// using ld = long double;

#define int long long

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

vector<int> primeFactors(int n) 
{ 
    bool done = false;
    vector<int> cnt;
    while (n % 2 == 0) 
    { 
        if (not done)
            cnt.push_back(2), done = true; 
        n = n/2; 
    } 

    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        done = false;
        while (n % i == 0) 
        { 
            if (not done)
                cnt.push_back(i), done = true;
            n = n/i; 
        } 
    } 
    if (n > 2) 
        cnt.push_back(n);
    
    return cnt;
} 

int C(int n, int r)
{
    if (r < 0)
        return 0;
    if (r == 0)
        return 1;
    return (n*(C(n - 1, r - 1))/r);
}

int biggestFactor(int n, int ub)
{
    int ans = 1;
    for(int i = 2; i <= ub; i++)
    {
        if (n % i == 0)
            ans = i;
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> pfm = primeFactors(m);
    int sz = pfm.size();
    int col = (sz == 0 ? 0 : biggestFactor(n, sz));
    // print(sz, col);
    if (col == 0)
        cout << "0\n";
    else if (n < col or n % col == 0)
        cout << min(n, col) << "\n";
    else
        cout << "0\n";
}

int32_t main()
{
    // FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    
    return 0;
}