#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)              \
    for (int _i = (start); _i < (end); _i++) \
        cout << (v[_i]) << " ";              \
    cout << "\n";
#define log(v)                                                \
    for (auto __i = ((v).begin()); __i != ((v).end()); __i++) \
        cout << *(__i) << " ";                                \
    cout << "\n";
#define print(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
        cout << "\n";                            \
    };

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

vector<long long> a;

bool good(int mid, int sum, int n)
{
    int meanOp = n * mid - sum;
    if (meanOp < 0)
        return false;

    int medianOp = 0;
    int start = (n % 2 == 0 ? (n/2) - 1 : n/2);

    for(int i = (n-1)/2; i < n; i++)
        medianOp += max(0LL, mid - a[i]);

    if (medianOp > meanOp)
        return false;
    
    return true;
}

void solve()
{
    int n;
    cin >> n;
    a.resize(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    sort(all(a));
    int median = (n % 2 == 0 ? a[(n / 2) - 1] : a[n / 2]);

    int left = median, right = 1e9 + 10, ans = -1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if (good(mid, sum, n))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    cout << n*ans - sum << "\n";
}

int32_t main()
{
    FIO;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}