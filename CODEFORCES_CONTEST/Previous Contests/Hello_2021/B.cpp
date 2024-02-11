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

void solve()
{   
    int n;
    cin >> n;

    ll leftmost = 1e10, rightmost = -1, rightcost = 0, leftcost = 0, maxcost = 0;
    ll max_len = 0;
    for(int i = 0; i < n; i++)
    {
        ll l, r, c;
        cin >> l >> r >> c;

        if (r - l + 1 > max_len or (max_len == r - l + 1 and c < maxcost))
        {
            max_len = r - l + 1;
            maxcost = c;
        }

        if (l < leftmost or (l == leftmost and c < leftcost))
        {
            leftcost = c;
            leftmost = l;
        }

        if (r > rightmost or (r == rightmost and c < rightcost))
        {
            rightcost = c;
            rightmost = r;
        }

        ll cur_len = rightmost - leftmost + 1;
        if (cur_len == max_len)
            cout << min(maxcost, leftcost + rightcost) << "\n";
        else
            cout << leftcost + rightcost << "\n";
    }
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}