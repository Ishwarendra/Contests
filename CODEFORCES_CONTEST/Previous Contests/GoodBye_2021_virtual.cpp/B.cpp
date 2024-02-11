#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
using ld = long double;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

string cust_min(string &a, string &b)
{
    int n = a.length(), m = b.length();
    for(int i = 0; i < (min(n, m)); i++)
    {
        if (a[i] != b[i])
            return min(a, b);
    }
    return (n < m) ? a : b;
}

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    stack<char> smol, smol2; // c -> a -> a se chota

    for(int i = 0; i < n; i++)
    {
        if (!smol.empty() and smol.top() <= s[i])
            break;

        smol.push(s[i]);
    }

    for(int i = 0; i < n; i++)
    {
        if (!smol2.empty() and smol2.top() < s[i])
            break;
            
        smol2.push(s[i]);
    }

    string ans, ans2;
    int st_size = smol.size();
    int st_size2 = smol2.size();

    while(st_size--)
        ans += smol.top(), smol.pop();
    while(st_size2--)
        ans2 += smol2.top(), smol2.pop();
    
    reverse(all(ans));
    reverse(all(ans2));
    st_size = ans.length();
    st_size2 = ans2.length();
    for(int i = st_size - 1; i >= 0; i--)
        ans += ans[i];
    for(int i = st_size2 - 1; i >= 0; i--)
        ans2 += ans2[i];
    // print(ans, ans2);
    cout << cust_min(ans, ans2) << "\n";  
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}   